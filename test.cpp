#include "ComplianceEngine.h"

using namespace std;

int main()
{
    // first, load all enclaves needed, i.e., key management, rule check, and binding
    if (LoadEnclaves() != SGX_SUCCESS)
    {
        cout << "Load Enclave Failure" << endl;
        return int(EngineStatus::kEnclaveLoadError);
    }

    // then, establish secure channel between enclave pairs through local attestation
    if (StartLocalAttesttion() != SGX_SUCCESS)
    {
        cout << "Local Attestion Failure" << endl;
        return int(EngineStatus::kLocalAttestationError);
    }

        // next, set up data server for synchronized world state query
    if (SetupDataServer() != uint32_t(EngineStatus::kOK))
    {
        cout << "Set Up Data Server Failure" << endl;
        return int(EngineStatus::kDataServerError);
    }

    // last, initialize peer client for transaction sign service request
    if (PreparePeerClient() != uint32_t(EngineStatus::kOK))
    {
        cout << "Initialize Peer Client Failure" << endl;
        return int(EngineStatus::kPeerClientError);
    }

    // then, launch main grpc server to start compliance engine service
    if (LaunchGRPCServer() != uint32_t(EngineStatus::kOK))
    {
        cout << "Launch gRPC Server Failure" << endl;
        return int(EngineStatus::kGRPCServerError);
    }

    return int(EngineStatus::kOK);
}
