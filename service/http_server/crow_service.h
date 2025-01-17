/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#pragma once

#include <crow.h>

#include "common/proto/signature_info.pb.h"
#include "interface/common/resdb_state_accessor.h"
#include "interface/common/resdb_txn_accessor.h"
#include "platform/config/resdb_config_utils.h"
#include "service/http_server/sdk_transaction.h"
#include "service/kv_service/proto/kv_server.pb.h"
#include "service/kv_service/resdb_kv_client.h"

namespace sdk {

class CrowService {
public:
  CrowService(resdb::ResDBConfig config, resdb::ResDBConfig server_config,
              uint16_t port_num = 18000);
  void run();

private:
  std::string GetAllBlocks(int batch_size, bool make_sublists=false);
  std::string ParseKVRequest(const KVRequest &kv_request);
  std::string ParseCreateTime(uint64_t createtime);
  resdb::ResDBConfig config_;
  resdb::ResDBConfig server_config_;
  uint16_t port_num_;
  ResDBKVClient kv_client_;
  resdb::ResDBTxnAccessor txn_client_;
  std::unordered_set<crow::websocket::connection *> users;
};

} // namespace sdk