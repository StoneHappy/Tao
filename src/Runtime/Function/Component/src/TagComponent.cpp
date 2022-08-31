#include "Tao/Function/Component/index.h"
namespace Tao::Function {
        RTTR_REGISTRATION//注册反射
        {
            rttr::registration::class_<TagComponent>("TagComponent")
                    .constructor<>()(rttr::policy::ctor::as_raw_ptr)
                    .property("Tag", &TagComponent::Tag);
        }
}