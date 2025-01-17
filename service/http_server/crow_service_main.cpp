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

#include "service/http_server/crow_service.h"

using resdb::GenerateResDBConfig;
using resdb::ResDBConfig;
using sdk::CrowService;

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("<client config path> <server config path>\n");
    return 0;
  }
  std::string client_config_file = argv[1];
  std::string server_config_file = argv[2];
  ResDBConfig config = GenerateResDBConfig(client_config_file);
  ResDBConfig server_config = GenerateResDBConfig(server_config_file);
  config.SetClientTimeoutMs(100000);

  CrowService service(config, server_config);
  service.run();
}
