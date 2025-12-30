
#pragma once

#include <BNM/UnityStructures.hpp>
#include <BNM/Method.hpp>
#include <BNM/Field.hpp>
#include <BNM/Property.hpp>
#include <BNM/MethodBase.hpp>
#include <BNM/FieldBase.hpp>
#include <BNM/PropertyBase.hpp>
#include <BNM/Il2CppHeaders.hpp>
#include <XRInput.hpp>
#include <utility>
#include <BNMResolve.hpp>
#include "SDK/Includes/GorillaTagger.h"
#include "SDK/Includes/VRRig.h"

static string MenuColorType = "normal";
static GameObject* menu = nullptr;
static GameObject* canvasObj = nullptr;
static GameObject* reference = nullptr;
static bool Page1inrange[21]; //1 above the buttons you have
static bool Page1ButtonActive[21];// 1 above the buttons you have
static string Page = "1";
static bool PageButton[4];// 1 above the pages you have
static Material* MenuTheme = (Material*)Material::GetClass().CreateNewObjectParameters(Shader::Find("GUI/Text Shader"));
static float offset;
static float lastClickTime = 0.f;
static float cooldownDuration = 0.25f;
static float elapsedTime = 0.f;
static Color ButtonClicked;
static Color ButtonNotClicked;
static Color startColor = Color(0.f, 0.f, 0.f);
static Color endColor = Color(1.f, 1.f, 1.f);
static float transitionDuration = 3.f;
static float proximityRange = 0.037f;
static Text* text2;
static Text* text3;
class ModMenu {
public:

    static void Draw() {
        menu = GameObject::CreatePrimitive(PrimitiveType::Cube);
        GameObject::Destroy(menu->GetComponent(Rigidbody::GetType()));
        GameObject::Destroy(menu->GetComponent(BoxCollider::GetType()));
        GameObject::Destroy(menu->GetComponent(Renderer::GetType()));
        menu->GetTransform()->SetLocalScale(Vector3(0.1f, 0.29f, 0.4f));
        GameObject *gameObject = GameObject::CreatePrimitive(PrimitiveType::Cube);
        GameObject::Destroy(gameObject->GetComponent(Rigidbody::GetType()));
        GameObject::Destroy(gameObject->GetComponent(BoxCollider::GetType()));
        gameObject->GetTransform()->SetParent(menu->GetTransform());
        gameObject->GetTransform()->SetRotation(Quaternion::identity);
        gameObject->GetTransform()->SetLocalScale(Vector3(0.1f, 1.05f, 1.21f));
        auto* renderer = (Renderer*)gameObject->GetComponent(Renderer::GetType());
        renderer->SetMaterial(MenuTheme);
        gameObject->GetTransform()->SetPosition(Vector3(0.05f, 0.f, 0.f));
        canvasObj = new GameObject();
        canvasObj->GetTransform()->SetParent(menu->GetTransform());
        auto* canvas = (Canvas*)canvasObj->AddComponent(Canvas::GetType());
        auto* canvasScaler = (CanvasScaler*)canvasObj->AddComponent(CanvasScaler::GetType());
        canvasObj->AddComponent(GraphicRaycaster::GetType());
        canvas->SetRenderMode(RenderMode::WorldSpace);
        canvasScaler->SetDynamicPixelsPerUnit(1000.f);
        auto* gameObject2 = new GameObject();
        gameObject2->GetTransform()->SetParent(canvasObj->GetTransform());
        auto* text = (Text*)gameObject2->AddComponent(Text::GetType());
        auto* font = (Font*)Resources::GetBuiltinResource(Font::GetType(), "Arial.ttf");
        text->SetFont(font);
        text->SetText(" Mod Menu [" + Page + "] "); // change the name poo poo head
        text->SetFontSize(1);
        text->SetAlignment(TextAnchor::MiddleCenter);
        text->SetTextResizeForBestFit(true);
        text->SetResizeTextMinSize(0);
        auto* component = (RectTransform*)text->GetComponent(RectTransform::GetType());
        component->SetLocalPosition(Vector3::zero);
        component->SetSizeDelta(Vector2(0.28f, 0.05f));
        component->SetPosition(Vector3(0.06f, 0.f, 0.205f));// 0.215f = 0.205f
        component->SetRotation(Quaternion::FromEuler(*new Vector3(180.f, 90.f, 90.f)));
    }
    static void DrawPageButton(string Text, float textypos, float buttonypos, string Pagenum, bool Button, int index) {
        GameObject *DisButton = GameObject::CreatePrimitive(PrimitiveType::Cube);
        GameObject::Destroy(DisButton->GetComponent(Rigidbody::GetType()));
        GameObject::Destroy(DisButton->GetComponent(BoxCollider::GetType()));
        DisButton->GetTransform()->SetParent(menu->GetTransform());
        DisButton->GetTransform()->SetRotation(menu->GetTransform()->GetRotation());
        DisButton->GetTransform()->SetLocalScale(Vector3(0.05f, 0.8f, 0.08f));
        DisButton->GetTransform()->SetLocalPosition(*new Vector3(0.54f, 0.f, buttonypos - offset / 1.2f));
        text2->GetTransform()->SetParent(canvasObj->GetTransform());
        Font* font = (Font*)Resources::GetBuiltinResource(Font::GetType(), "Arial.ttf");
        text2->SetFont(font);
        text2->SetText(std::move(Text));
        text2->SetColor(Color::white);
        text2->SetFontSize(1);
        text2->SetAlignment(TextAnchor::MiddleCenter);
        text2->SetTextResizeForBestFit(true);
        text2->SetResizeTextMinSize(0);
        text2->GetRectTransform()->SetLocalPosition(Vector3::zero);
        text2->GetRectTransform()->SetSizeDelta(Vector2(0.2f, 0.03f)) ;
        text2->GetRectTransform()->SetLocalPosition(Vector3(0.064f, 0.f, textypos - offset / 3.05f));
        Quaternion newRotation = DisButton->GetTransform()->GetRotation() * Quaternion::FromEuler(180.f, 90.f, 90.f);
        text2->GetRectTransform()->SetRotation(newRotation);
        float isclicked = Vector3::Distance(DisButton->GetTransform()->GetPosition(), reference->GetTransform()->GetPosition());
        if (isclicked <= proximityRange && Time::GetTime() - lastClickTime > cooldownDuration)
        {
            Button = true;
            PageButton[index] = Button;
            Page = std::move(Pagenum);
            //GorillaTagger.Instance.offlineVRRig.PlayHandTap(4, false, 0.05f);
            GameObject::Destroy(menu);
            GameObject::Destroy(reference);
            menu = nullptr;
            reference = nullptr;
            lastClickTime = Time::GetTime();
        }
        else if (isclicked > proximityRange) {
            Button = false;
            PageButton[index] = Button;
        }
        auto* mat = (Renderer*)DisButton->GetComponent(Renderer::GetType());
        if (Button) { mat->GetMaterial()->SetColor(ButtonClicked); } else { mat->GetMaterial()->SetColor(ButtonNotClicked); }
        GameObject::Destroy(DisButton, Time::GetDeltaTime());
        GameObject::Destroy(text2, Time::GetDeltaTime());
    }
    static void Drawsingleclickbutton(string Text, float textypos, float buttonypos, bool& ButtonRange, bool& Mod, int index) {
        GameObject* DisButton = GameObject::CreatePrimitive(PrimitiveType::Cube);
        GameObject::Destroy(DisButton->GetComponent(Rigidbody::GetType()));
        GameObject::Destroy(DisButton->GetComponent(BoxCollider::GetType()));
        DisButton->GetTransform()->SetParent(menu->GetTransform());
        DisButton->GetTransform()->SetRotation(menu->GetTransform()->GetRotation());
        DisButton->GetTransform()->SetLocalScale(Vector3(0.05f, 0.8f, 0.08f));
        DisButton->GetTransform()->SetLocalPosition(Vector3(0.54f, 0.f, buttonypos - offset / 1.2f));
        text3->GetTransform()->SetParent(canvasObj->GetTransform());
        Font* font3 = (Font*)Resources::GetBuiltinResource(Font::GetType(), "Arial.ttf");
        text3->SetFont(font3);
        text3->SetText(std::move(Text));
        text3->SetColor(Color::white);
        text3->SetFontSize(1);
        text3->SetAlignment(TextAnchor::MiddleCenter);
        text3->SetTextResizeForBestFit(true);
        text3->SetResizeTextMinSize(0);
        RectTransform *component = text3->GetRectTransform();
        component->SetLocalPosition(Vector3::zero);
        component->SetSizeDelta(Vector2(0.2f, 0.03f));
        component->SetLocalPosition(Vector3(0.064f, 0.f, textypos - offset / 3.05f));
        Quaternion newRotation = DisButton->GetTransform()->GetRotation() * Quaternion::FromEuler(180.f, 90.f, 90.f);
        component->SetRotation(newRotation);
        float isclicked = Vector3::Distance(DisButton->GetTransform()->GetPosition(), reference->GetTransform()->GetPosition());
        if (isclicked <= proximityRange && !ButtonRange &&
                Time::GetTime() - lastClickTime > cooldownDuration) {
            ButtonRange = true;
            Mod = !Mod;
            GlobalNamespace::GorillaTagger::_instance()->offlineVRRig<GlobalNamespace::VRRig*>()->PlayHandTap(4, false, 0.05f);
            lastClickTime = Time::GetTime();
        }
        else if (isclicked > proximityRange && ButtonRange)
        {
            ButtonRange = false;
        }
        if (Mod)
        {
            auto* remdeder = (Renderer*)DisButton->GetComponent(Renderer::GetType());
            remdeder->GetMaterial()->SetColor(ButtonClicked);
        }
        else
        {
            auto* remdeder1 = (Renderer*)DisButton->GetComponent(Renderer::GetType());
            remdeder1->GetMaterial()->SetColor(ButtonNotClicked);
        }
        Page1inrange[index] = ButtonRange;
        Page1ButtonActive[index] = Mod;
        GameObject::Destroy(DisButton, Time::GetDeltaTime());
        GameObject::Destroy(text2, Time::GetDeltaTime());
    }
    static void Prefix() {
        if (XRInput::GetBoolFeature(SecondaryButton, Left) && menu == nullptr) {
            // dont mess with this or your menu wont work
            Draw();
            if (reference == nullptr) {
                reference = GameObject::CreatePrimitive(PrimitiveType::Sphere);
                GameObject::Destroy(reference->GetComponent(SphereCollider::GetType()));
                reference->GetTransform()->SetParent(GameObject::Find("RightHand Controller")->GetTransform());
                reference->GetTransform()->SetLocalPosition(Vector3(0.f, 0.f, 0.1f));
                reference->GetTransform()->SetLocalScale(Vector3(0.01f, 0.01f, 0.01f));
            }
        }
        else
        {
            if (!XRInput::GetBoolFeature(SecondaryButton, Left) && menu != nullptr)
            {
                GameObject::Destroy(menu);
                GameObject::Destroy(reference);
                menu = nullptr;
                reference = nullptr;
            }
        }
        if (XRInput::GetBoolFeature(SecondaryButton, Left) && menu != nullptr) {
            // dont mess with this or your menu wont work
            menu->GetTransform()->SetPosition(GameObject::Find("LeftHand Controller")->GetTransform()->GetPosition());
            menu->GetTransform()->SetRotation(GameObject::Find("LeftHand Controller")->GetTransform()->GetRotation());
        }
        if (XRInput::GetBoolFeature(SecondaryButton, Left) && menu != nullptr) {

            if (Page == "1") {
                DrawPageButton("-------->", 0.157f, 0.39f, "2", PageButton[2], 2);
                DrawPageButton("<--------", 0.117f, 0.29f, "2", PageButton[2], 2); // make this go to the last page
                Drawsingleclickbutton("Quit Game <color=lime>[W]</color>", 0.077f, 0.19f, ref(Page1inrange[1]),  ref(Page1ButtonActive[1]), 1);
                Drawsingleclickbutton("Join Public <color=lime>[W]</color>", -0.043f, -0.11f, ref(Page1inrange[2]),  ref(Page1ButtonActive[2]), 2);
                Drawsingleclickbutton("Disconnect <color=lime>[W]</color>", -0.083f, -0.21f, ref(Page1inrange[3]), ref(Page1ButtonActive[3]), 3);
                Drawsingleclickbutton("", 0.037f, 0.09f, ref(Page1inrange[4]), ref(Page1ButtonActive[4]), 4);
                Drawsingleclickbutton("", -0.003f, -0.01f, ref(Page1inrange[5]), ref(Page1ButtonActive[5]), 5);
                Drawsingleclickbutton("", -0.203f, -0.11f, ref(Page1inrange[6]), ref(Page1ButtonActive[6]), 6);
                Drawsingleclickbutton("", -0.243f, -0.21f, ref(Page1inrange[7]), ref(Page1ButtonActive[7]), 7);
            }
            if (Page == "2")
            {

            }
            if (Page == "3")
            {
                // put buttons or whatever and script the reset
            }

        }
        // page 1
        if (Page1ButtonActive[1]) {
            Application::Quit();
        }
        if (Page1ButtonActive[2]) {
            PhotonNetwork::JoinRandomRoom();
            Page1ButtonActive[2] = false;
        }
        if (Page1ButtonActive[3]) {
            PhotonNetwork::Disconnect();
            Page1ButtonActive[3] = false;
        }
        if (Page1ButtonActive[4]) {

        }
        if (Page1ButtonActive[5]) {

        }
        if (Page1ButtonActive[6]) {

        }
        if (Page1ButtonActive[7]) {


        }
        if (Page1ButtonActive[8]) {

        }
        if (Page1ButtonActive[9]) {

        }
        if (Page1ButtonActive[10]) {

        }
        if (Page1ButtonActive[11]) {

        }
        if (Page1ButtonActive[12]) {

        }
        if (Page1ButtonActive[13]) {

        }
        if (Page1ButtonActive[14]) {

        }
        if (MenuColorType == "normal")
        {
            ButtonClicked = Color(0.4f, 0.4f, 0.4f);
            ButtonNotClicked = Color(0.65f, 0.65f, 0.65f);
            // this is the color changer
            if (elapsedTime < transitionDuration)
            {
                MenuTheme->SetColor(Color::Lerp(startColor, endColor, elapsedTime / transitionDuration));
                elapsedTime += Time::GetDeltaTime();
                if (elapsedTime >= transitionDuration)
                {
                    elapsedTime = 0.f;
                }
                // dont want the color changer just do MenuTheme.color =  new Color(0.1f, 0.1f, 0.1f); its a random color
            }
        }
    }
};