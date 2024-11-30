/** @file client.c
 * 
 * Implementation of the protocol buffers RPC client.
 * 
 * Copyright 2009 Simon Kallweit
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 *     
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <lwpb/lwpb.h>


/**
 * Initializes the client.
 * @param client Client
 * @param transport Transport implementation
 */
void lwpb_client_init(struct lwpb_client *client, lwpb_transport_t transport)
{
    LWPB_ASSERT(transport, "Transport implementation missing");
    
    client->transport = transport;
    client->arg = NULL;
    client->request_handler = NULL;
    client->response_handler = NULL;
    client->done_handler = NULL;
    
    // Register the client in the transport implementation
    client->transport->transport_funs->register_client(client->transport, client);
}

/**
 * Sets the user argument to be passed back with the handlers.
 * @param client Client
 * @param arg User argument
 */
void lwpb_client_arg(struct lwpb_client *client, void *arg)
{
    client->arg = arg;
}

/**
 * Sets the handlers.
 * @param client Client
 * @param request_handler Request message handler
 * @param response_handler Response message handler
 * @param done_handler Call done handler 
 */
void lwpb_client_handler(struct lwpb_client *client,
                         lwpb_client_request_handler_t request_handler,
                         lwpb_client_response_handler_t response_handler,
                         lwpb_client_done_handler_t done_handler)
{
    client->request_handler = request_handler;
    client->response_handler = response_handler;
    client->done_handler = done_handler;
}

/**
 * Starts an RPC call.
 * @param client Client
 * @param method_desc Method descriptor
 * @return Returns LWPB_ERR_OK if successful.
 */
lwpb_err_t lwpb_client_call(struct lwpb_client *client,
                            const struct lwpb_method_desc *method_desc)
{
    LWPB_ASSERT(client->transport, "Transport implementation missing");
    LWPB_ASSERT(client->request_handler, "Request handler missing");
    LWPB_ASSERT(client->response_handler, "Response handler missing");
    LWPB_ASSERT(client->done_handler, "Call done handler missing");
    
    // Forward the call to the transport implementation
    return client->transport->transport_funs->call(client->transport, client, method_desc);
}

/**
 * Cancels the currently running RPC call.
 * @param client Client
 */
void lwpb_client_cancel(struct lwpb_client *client)
{
    // Forward the request to the transport implementation
    client->transport->transport_funs->cancel(client->transport, client);
}
