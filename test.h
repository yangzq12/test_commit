#pragma once

#include <map>
#include <iostream>
#include <string>
#include <stdio.h>
#include "KeyManagementEnclave_u.h"
#include "RuleEnclave_u.h"
#include "BindingEnclave_u.h"
#include "DataServer.h"
#include "RegulatorServer.h"
#include "sgx_urts.h"
#include "EnclaveId.h"

using namespace std;

enum class EngineStatus
{
    kOK = 0,
    kEnclaveLoadError,
    kLocalAttestationError,
    kDataServerError,
    kGRPCServerError,
    kPeerClientError,
};

// maximal size of enclave input/output buffer size
extern uint64_t kMaxOutSize;

#define KEY_MANAGEMENT_ENCLAVE_FILENAME "key_management_enclave.signed.so"
#define RULE_ENCLAVE_FILENAME "rule_enclave.signed.so"
#define BINDING_ENCLAVE_FILENAME "binding_enclave.signed.so"

extern sgx_enclave_id_t g_key_management_enclave_id;
extern sgx_enclave_id_t g_rule_enclave_id;
extern sgx_enclave_id_t g_binding_enclave_id;

// map from enclave id to enclave index (used for ocall forward)
extern std::map<sgx_enclave_id_t, SubModule> g_enclave_id_map;

extern DataServer kDataServer;
// extern PeerSigTxClient regulator_client;

extern int n_workers;
extern ThreadPool pool;

// Launch helper functions
uint32_t LoadEnclaves();
uint32_t StartLocalAttesttion();
uint32_t SetupDataServer();
uint32_t LaunchGRPCServer();
uint32_t PreparePeerClient();

// Logout helper functions
uint32_t SafeLogout();
