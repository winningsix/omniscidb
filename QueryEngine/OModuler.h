/*
 * Copyright 2021 Intel, Inc.
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

#ifndef OMNISCI_OMODULER_H
#define OMNISCI_OMODULER_H

#include "RelAlgDagBuilder.cpp"

class WorkUnit {
 public:
  int executeWithData(int input){ return 0;};
};

class OModuler {
 public:
  OModuler(const details::RelAlgDispatcher& dp) : dp_(dp) {}

  // TODO define input/output
  std::shared_ptr<RelAlgNode> ast_convert(const rapidjson::Value& rels);
  WorkUnit kernel_createWorkUnit(std::shared_ptr<RelAlgNode> node) { return WorkUnit(); };
  std::shared_ptr<char> data_convert() { return nullptr; };

 private:
  details::RelAlgDispatcher dp_;
};



#endif  // OMNISCI_OMODULER_H