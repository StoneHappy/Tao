#include <gtest/gtest.h>
#include <Tao/Function/Component/index.h>
#include <Tao/Function/Script/index.h>
TEST(TaoUnitTest, Component)
{
	Tao::Function::GameObject* gobj = new Tao::Function::GameObject("obj");
	gobj->AddComponent("TagComponent");
	EXPECT_EQ(dynamic_cast<Tao::Function::TagComponent*>(gobj->GetComponent("TagComponent"))->Tag, "obj");
	dynamic_cast<Tao::Function::TagComponent*>(gobj->GetComponent("TagComponent"))->Tag = "Tag1";
	dynamic_cast<Tao::Function::TagComponent*>(gobj->GetComponent("TagComponent"))->Tag = "Tag2";
	EXPECT_EQ(dynamic_cast<Tao::Function::TagComponent*>(gobj->GetComponent("TagComponent"))->Tag, "Tag2");
	Tao::Function::TagComponent* tag1 = dynamic_cast<Tao::Function::TagComponent*>(gobj->GetComponents("TagComponent")[1]);
	tag1->Tag = "tag1";
	EXPECT_EQ(dynamic_cast<Tao::Function::TagComponent*>(gobj->GetComponents("TagComponent")[1])->Tag, "tag1");
}

TEST(TaoUnitTest, ScriptSystem)
{
	Tao::Function::ScriptSystem scriptSystem;
	int rnt = scriptSystem.runCode("return 1");
	EXPECT_EQ(rnt, 1);
}