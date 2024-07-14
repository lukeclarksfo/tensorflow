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
    Activity::Atrributes attributes(std::move(additional_attributes));
    
    if(context)
    {
        attributes.merge(Activity::Attributes({
            {"node_name", context->op_kernel().def().name()},
            {"step_id", absl::StrCat(context->step_id()},
            {"device", context>device()->name()},
            {"op", context->op_kernel().def().op()},
            {"iter_num", absl::StrCat(context->frame_iter().iter_id)},
            {"inputs", absl::StrJoin(context->op_kernel().def().input(), ";")},
        }));
    }

    return std::make_unique<Activity>(name, category, std::move(attributes));
}

} // namespace activity_watcher
} // namespace tensorflow