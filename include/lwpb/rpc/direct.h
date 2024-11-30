/** @file direct.h
 * 
 * Direct RPC transport implementation.
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

#ifndef __LWPB_RPC_DIRECT_H__
#define __LWPB_RPC_DIRECT_H__

#include <lwpb/lwpb.h>


/** Direct RPC transport implementation */
struct lwpb_transport_direct {
    struct lwpb_transport super;
    struct lwpb_client *client;
    struct lwpb_server *server;
};

lwpb_transport_t lwpb_transport_direct_init(struct lwpb_transport_direct *transport_direct);

#endif // __LWPB_RPC_DIRECT_H__
