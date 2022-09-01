#pragma once
#include "cpp-utilities/dll.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <rttr/registration>
namespace Tao
{
    namespace Function {
        class GameObject;
        class CPP_UTIL_API Component {
        public:
            Component() = default;
            virtual ~Component() = default;

            GameObject* game_object(){return game_object_;}
            void set_game_object(GameObject* game_object){game_object_=game_object;}
        private:
            GameObject* game_object_;
        };

        class CPP_UTIL_API GameObject {
        public:
            GameObject();
            GameObject(std::string name);
            ~GameObject();

            std::string& name(){return name_;}
            void set_name(std::string name){name_=name;}

            /**
             * @brief add component by component type name
             * 
             * 
             * #### Example Code
             * ```cpp
             * GameObject gobj;
             * gobj.AddComponent("TagComponent");
             * ```
             * 
             * @param component_type_name 
             * @return Component* Component ptr
             */
            Component* AddComponent(std::string component_type_name);

            /**
             * @brief Get the Component object
             * #### Example Code
             * ```cpp
             * GameObject gobj;
             * gobj.AddComponent("TagComponent");
             * dynamic_cast<Tao::Function::TagComponent*>(gobj->GetComponent("TagComponent"))->Tag;
             * ```
             * 
             * @param component_type_name 
             * @return Component* 
             */
            Component* GetComponent(std::string component_type_name);

            /// 获取所有同名组件
            /// \param component_type_name 组件类名
            /// \return
            std::vector<Component*>& GetComponents(std::string component_type_name);

        private:
            std::string name_;
            std::unordered_map<std::string,std::vector<Component*>> component_type_instance_map_;
        };

        class TagComponent :public Component
        {
        public:
            TagComponent() = default;
            ~TagComponent() = default;
            std::string Tag;
        };
    }
}