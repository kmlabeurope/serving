#include "tensorflow_serving/servables/tensorflow/model_info_impl.h"

#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "tensorflow/cc/saved_model/loader.h"
#include "tensorflow/contrib/session_bundle/bundle_shim.h"
#include "tensorflow/contrib/session_bundle/session_bundle.h"
#include "tensorflow/core/lib/core/errors.h"
#include "tensorflow_serving/core/servable_handle.h"

namespace tensorflow {
namespace serving {

namespace {

Status ValidateModelInfoRequest(const ModelInfoRequest& request) {
  return tensorflow::Status::OK();
}

}  // namespace

Status ModelInfoImpl::GetModelInfo( ServerCore* core, const ModelInfoRequest& request, ModelInfoResponse* response) {
  TF_RETURN_IF_ERROR(ValidateModelInfoRequest(request));
  const std::vector<ServableId> available_servables = core->ListAvailableServableIds();

  //std::cout << "[i] GetModelInfo..." << request.model_name() << std::endl;
  if(request.model_name().empty()) {
    for (auto it = available_servables.begin() ; it != available_servables.end(); ++it) {
      ModelInfo *mi = response->add_servables();
      mi->set_name(it->name);
      mi->set_version(it->version);
    }
  } else {
    for (const auto& servable : available_servables) {
      if(!servable.name.compare(request.model_name())) {
        //std::cout << "[i] ModelInfoRequest.model_name ==> returning a single servables." << std::endl;
        ModelInfo *mi = response->add_servables();
        mi->set_name(servable.name);
        mi->set_version(servable.version);
      }
    }
  }

  return tensorflow::Status::OK();
}

}  // namespace serving
}  // namespace tensorflow
