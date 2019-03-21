#ifndef TENSORFLOW_SERVING_SERVABLES_TENSORFLOW_SERVER_IMPL_H_
#define TENSORFLOW_SERVING_SERVABLES_TENSORFLOW_SERVER_IMPL_H_

#include "tensorflow/core/lib/core/status.h"
#include "tensorflow_serving/apis/server.pb.h"
#include "tensorflow_serving/model_servers/server_core.h"

namespace tensorflow {
namespace serving {

class ModelInfoImpl {
 public:
  
  static Status GetModelInfo(ServerCore* core,
                        const ModelInfoRequest& request, 
                        ModelInfoResponse* response);

 private:
  
};

}  // namespace serving
}  // namespace tensorflow

#endif  // TENSORFLOW_SERVING_SERVABLES_TENSORFLOW_SERVER_IMPL_H_
