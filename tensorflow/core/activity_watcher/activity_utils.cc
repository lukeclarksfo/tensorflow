#include "tensorflow/core/activity_watcher/activity_utils.h"

#include <memory>
#include <utility>

#include "absl/strings/str_cat.h"
#include "absl/strings/str_join.h"
#include "tensorflow/core/activity_watcher/activity.h"
#include "tensorflow/core/framework/op_kernel.h"
#include "tsl/platform/types.h"

namespace tensorflow {
namespace activity_watcher {

std::unique_ptr<Activity> ActivityFromContext(
    OpKernelContext* context, tsl::string name, ActivityCategory category,
    Activity::Attributes additional_attributes) {
        
    }

}
}