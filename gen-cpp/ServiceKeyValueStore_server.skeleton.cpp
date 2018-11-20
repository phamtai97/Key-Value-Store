// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "ServiceKeyValueStore.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

class ServiceKeyValueStoreHandler : virtual public ServiceKeyValueStoreIf {
 public:
  ServiceKeyValueStoreHandler() {
    // Your initialization goes here
  }

  void getApi(MsgGetResponse& _return, const MsgGetRequest& msgGetRequest) {
    // Your implementation goes here
    printf("getApi\n");
  }

  void putApi(MsgSetResponse& _return, const MsgSetRequest& msgSetRequest) {
    // Your implementation goes here
    printf("putApi\n");
  }

  void removeApi(MsgRemoveResponse& _return, const MsgRemoveRequest& msgRemoveRequest) {
    // Your implementation goes here
    printf("removeApi\n");
  }

  void existApi(MsgExistResponse& _return, const MsgExistRequest& msgExistRequest) {
    // Your implementation goes here
    printf("existApi\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::apache::thrift::stdcxx::shared_ptr<ServiceKeyValueStoreHandler> handler(new ServiceKeyValueStoreHandler());
  ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new ServiceKeyValueStoreProcessor(handler));
  ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
