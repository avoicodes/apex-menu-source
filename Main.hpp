#pragma once

//#include "SDK/Includes/GorillaTagger.h"

class ButtonInfo
{
public:
    string buttonText = "-";
    function<void()> method = nullptr;
    function<void()> enableMethod = nullptr;
    function<void()> disableMethod = nullptr;
    bool enabled = false;
    bool isTogglable = true;
    string overlapText = "";
    string toolTip = "This button doesn't have a tooltip/tutorial.";
};

class Main
{
private:

public:
    class Buttons2 {
    public:
        inline static std::vector<std::vector<ButtonInfo>> buttons = {
                {
                        ButtonInfo{.buttonText = "Test Button", .method = ModsThing::JoinDiscord, .isTogglable = true},
                }
        };
    };
    class ButtonCollider : BNM::UnityEngine::MonoBehaviour {
    public:
        string relatedText;
        static inline float buttonCooldown = 0.f;

        void OnTriggerEnter(Collider* collider)
        {
            if (Time::GetTime() > buttonCooldown && collider == Main::buttonCollider && Main::menu != nullptr)
            {
                buttonCooldown = Time::GetTime() + 0.2f;
                XRInput::SendHapticImpulse(Right, 1.f / 2.f, .15f / 2.f);
                //   GlobalNamespace::GorillaTagger::_instance()->offlineVRRig<GlobalNamespace::VRRig*>()->PlayHandTap(8, false, 0.4f); //Change to PlayHandTapLocal if needed
                Toggle(this->relatedText);
            }
        }
        static Class GetClass() //Im not sure if this will work or not but itl do
        {
            return Class("", "ButtonCollider");
        }
        static MonoType* GetType()
        {
            static MonoType *type = GetClass().GetMonoType();
            return type;
        }
    };
    static inline GameObject* menu;
    static inline GameObject* menuBackground;
    static inline GameObject* reference;
    static inline GameObject* canvasObject;

    static inline Collider* buttonCollider;
    static inline Text* fpsObject;

    static inline int pageNumber = 0;
    static inline int buttonsType = 0;

    static inline Color backgroundColor = Color(0.f, 0.7f, 1.f);
    static inline Color buttonColor = Color(0.f, 0.5f, 1.f);

    static void Plugin()
    {
        bool toOpen = XRInput::GetBoolFeature(SecondaryButton, Left);

        if (menu == nullptr)
        {
            try
            {
                if (toOpen)
                {
                    //GlobalNamespace::GorillaTagger::_instance()->offlineVRRig<GlobalNamespace::VRRig *>()->PlayHandTap(8, false, 0.4f); //Change to PlayHandTapLocal if needed
                    CreateMenu();
                    RecenterMenu();
                    if (reference == nullptr)
                    {
                        CreateReference();
                    }
                }
                else
                {
                    GameObject::Destroy(menu);
                    menu = nullptr;

                    GameObject::Destroy(reference);
                    reference = nullptr;
                }
            }
            catch (runtime_error d){}
        }
        if (fpsObject != nullptr)
        {
            fpsObject->SetText("FPS: " + to_string(std::ceil(1.f / Time::GetUnscaledDeltaTime())));
        }

        for (auto& x : Buttons2::buttons)
        {
            for (auto& y : x)
            {
                if (y.enabled)
                {
                    if (y.method != nullptr)
                    {
                        y.method();
                    }
                }
            }
        }
    }
    static void CreateMenu()
    {
        menu = GameObject::CreatePrimitive(Cube);
        GameObject::Destroy(menu->GetComponent(Rigidbody::GetType()));
        GameObject::Destroy(menu->GetComponent(BoxCollider::GetType()));
        GameObject::Destroy(menu->GetComponent(Renderer::GetType()));
        menu->GetTransform()->SetLocalScale(Vector3(0.1f, 0.3f, 0.4f));

// Menu Background
        menuBackground = GameObject::CreatePrimitive(Cube);
        GameObject::Destroy(menuBackground->GetComponent(Rigidbody::GetType()));
        GameObject::Destroy(menuBackground->GetComponent(BoxCollider::GetType()));
        menuBackground->GetTransform()->SetParent(menu->GetTransform());
        menuBackground->GetTransform()->SetRotation(Quaternion::identity);
        menuBackground->GetTransform()->SetLocalScale(Vector3(0.1f, .1f, 1.f));
        auto* backRend = (Renderer*)menuBackground->GetComponent(Renderer::GetType());
        backRend->GetMaterial()->SetColor(backgroundColor);
        menuBackground->GetTransform()->SetPosition(Vector3(0.05f, 0.f, -0.04f));

// Canvas
        canvasObject = new GameObject();
        canvasObject->GetTransform()->SetParent(menu->GetTransform());
        auto* canvas = (Canvas*)canvasObject->AddComponent(Canvas::GetType());
        auto* canvasScaler = (CanvasScaler*)canvasObject->AddComponent(CanvasScaler::GetType());
        canvasObject->AddComponent(GraphicRaycaster::GetType());
        canvas->SetRenderMode(WorldSpace);
        canvasScaler->SetDynamicPixelsPerUnit(1000.f);

// Title and FPS
        GameObject *textobj = new GameObject();
        auto* text = (Text*)textobj->AddComponent(Text::GetType());
        text->GetTransform()->SetParent(canvasObject->GetTransform());
        text->SetFont((Font*)Resources::GetBuiltinResource(Font::GetType(), "Arial.ttf"));
        text->SetText("Template Menu");
        text->SetFontSize(1);
        text->SetColor(Color::white);
        text->SetSupportRichText(true);
        text->SetAlignment(MiddleCenter);
        text->SetTextResizeForBestFit(true);
        text->SetResizeTextMinSize(0);
        auto* component = (RectTransform*)text->GetComponent(RectTransform::GetType());
        component->SetLocalPosition(Vector3::zero);
        component->SetSizeDelta(Vector2(0.28f, 0.05f));
        component->SetPosition(Vector3(0.06f, 0.f, 0.175f));
        component->SetRotation(Quaternion::FromEuler(Vector3(180.f, 90.f, 90.f)));

        // Page Buttons
        GameObject* gameObject = GameObject::CreatePrimitive(Cube);

        GameObject::Destroy(gameObject->GetComponent(Rigidbody::GetType()));
        auto* bc = (BoxCollider*)gameObject->GetComponent(BoxCollider::GetType());
        bc->SetIsTrigger(true);
        gameObject->GetTransform()->SetParent(menu->GetTransform());
        gameObject->GetTransform()->SetRotation(Quaternion::identity);
        gameObject->GetTransform()->SetLocalScale(Vector3(0.09f, 0.8f, 0.08f));
        gameObject->GetTransform()->SetLocalPosition(Vector3(0.56f, 0.f, -0.3575f));
        auto* rend = (Renderer*)gameObject->GetComponent(Renderer::GetType());
        rend->GetMaterial()->SetColor(buttonColor);
        //auto* btcs = (ButtonCollider*)gameObject->AddComponent(ButtonCollider::GetType());
        //btcs->relatedText = "NextPage";

        GameObject *textobj2 = new GameObject();
        auto* text2 = (Text*)textobj2->AddComponent(Text::GetType());
        text2->SetFont((Font*)Resources::GetBuiltinResource(Font::GetType(), "Arial.ttf"));
        text2->SetText("Next Page");
        text2->SetFontSize(1);
        text2->SetAlignment(MiddleCenter);
        text2->SetTextResizeForBestFit(true);
        text2->SetResizeTextMinSize(0);
        auto* component2 = (RectTransform*)text2->GetComponent(RectTransform::GetType());
        component2->SetLocalPosition(Vector3::zero);
        component2->SetSizeDelta(Vector2(0.2f, 0.03f));
        component2->SetLocalPosition(Vector3(0.064f, 0.f, 0.111f - 0.65f / 2.55f));
        component2->SetRotation(Quaternion::FromEuler(Vector3(180.f, 90.f, 90.f)));

        GameObject* gameObject2 = GameObject::CreatePrimitive(Cube);

        GameObject::Destroy(gameObject->GetComponent(Rigidbody::GetType()));
        auto* bc2 = (BoxCollider*)gameObject->GetComponent(BoxCollider::GetType());
        bc2->SetIsTrigger(true);
        gameObject2->GetTransform()->SetParent(menu->GetTransform());
        gameObject2->GetTransform()->SetRotation(Quaternion::identity);
        gameObject2->GetTransform()->SetLocalScale(Vector3(0.09f, 0.8f, 0.08f));
        gameObject2->GetTransform()->SetLocalPosition(Vector3(0.56f, 0.f, -0.4875f));
        auto* rend2 = (Renderer*)gameObject2->GetComponent(Renderer::GetType());
        rend2->GetMaterial()->SetColor(buttonColor);
        //auto* btcs2 = (ButtonCollider*)gameObject->AddComponent(ButtonCollider::GetType());
        //btcs2->relatedText = "PreviousPage";

        GameObject *textobj3 = new GameObject();
        auto* text3 = (Text*)textobj3->AddComponent(Text::GetType());
        text3->SetFont((Font*)Resources::GetBuiltinResource(Font::GetType(), "Arial.ttf"));
        text3->SetText("Next Page");
        text3->SetFontSize(1);
        text3->SetAlignment(MiddleCenter);
        text3->SetTextResizeForBestFit(true);
        text3->SetResizeTextMinSize(0);
        auto* component3 = (RectTransform*)text2->GetComponent(RectTransform::GetType());
        component3->SetLocalPosition(Vector3::zero);
        component3->SetSizeDelta(Vector2(0.2f, 0.03f));
        component3->SetLocalPosition(Vector3(0.064f, 0.f, 0.111f - 0.78f / 2.55f));
        component3->SetRotation(Quaternion::FromEuler(Vector3(180.f, 90.f, 90.f)));

        /*vector<ButtonInfo> activeButtons = Buttons2::buttons[buttonsType];
        int x = pageNumber * 5;
        int y = min(x + 8, (int)activeButtons.size());

        for (int i = x; i < y; ++i)
        {
            CreateButton((i - x) * .13f, activeButtons[i]);
        }*/

    }
    static void CreateButton(float offset, ButtonInfo method)
    {
        GameObject* gameObject = GameObject::CreatePrimitive(Cube);

        GameObject::Destroy(gameObject->GetComponent(Rigidbody::GetType()));
        auto* bc = (BoxCollider*)gameObject->GetComponent(BoxCollider::GetType());
        bc->SetIsTrigger(true);
        gameObject->GetTransform()->SetParent(menu->GetTransform());
        gameObject->GetTransform()->SetRotation(Quaternion::identity);
        gameObject->GetTransform()->SetLocalScale(Vector3(0.09f, 0.8f, 0.08f));
        gameObject->GetTransform()->SetLocalPosition(Vector3(0.56f, 0.f, 0.28f - offset));
        auto* btc = (Main::ButtonCollider*)gameObject->AddComponent(Main::ButtonCollider::GetType());
        btc->relatedText = method.buttonText;

        auto* rend = (Renderer*)gameObject->GetComponent(Renderer::GetType());
        if (method.enabled)
        {
            rend->GetMaterial()->SetColor(backgroundColor);
        }
        else
        {
            rend->GetMaterial()->SetColor(buttonColor);
        }

        GameObject *textobj = new GameObject();
        auto* text = (Text*)textobj->AddComponent(Text::GetType());
        text->SetFont((Font*)Resources::GetBuiltinResource(Font::GetType(), "Arial.ttf"));
        text->SetText(method.buttonText);
        if (empty(method.overlapText))
        {
            text->SetText(method.overlapText);
        }
        text->SetSupportRichText(true);
        text->SetFontSize(1);
        if (method.enabled)
        {
            text->SetColor(Color::green);
        }
        else
        {
            text->SetColor(Color::white);
        }
        text->SetAlignment(MiddleCenter);
        text->SetFontStyle(Italic);
        text->SetTextResizeForBestFit(true);
        text->SetResizeTextMinSize(0);
        auto* component = (RectTransform*)text->GetComponent(RectTransform::GetType());
        component->SetLocalPosition(Vector3::zero);
        component->SetSizeDelta(Vector2(0.2f, 0.03f));
        component->SetLocalPosition(Vector3(0.064f, 0.f, 0.111f - offset / 2.55f));
        component->SetRotation(Quaternion::FromEuler(Vector3(180.f, 90.f, 90.f)));
    }
    static ButtonInfo* GetIndex(const string& rename)
    {
        for (auto& c : Buttons2::buttons)
        {
            for (auto& b : c)
            {
                if (b.buttonText == rename)
                {
                    return &b;
                }
            }
        }
        return nullptr;
    }
    static void RecreateMenu()
    {
        if (menu != nullptr)
        {
            GameObject::Destroy(menu);
            menu = nullptr;

            CreateMenu();
            RecenterMenu();
        }
    }
    static void RecenterMenu()
    {
        menu->GetTransform()->SetPosition(GameObject::Find("LeftHand Controller")->GetTransform()->GetPosition()); // Will Work for Copies and Most Fangames
        menu->GetTransform()->SetRotation(GameObject::Find("LeftHand Controller")->GetTransform()->GetRotation());
    }
    static void CreateReference()
    {
        reference = GameObject::CreatePrimitive(Sphere);
        reference->GetTransform()->SetParent(GameObject::Find("RightHand Controller")->GetTransform());
        auto* rend = (Renderer*)reference->GetComponent(Renderer::GetType());
        rend->GetMaterial()->SetColor(backgroundColor);
        reference->GetTransform()->SetLocalPosition(Vector3(0.f, -0.1f, 0.f));
        reference->GetTransform()->SetLocalScale(Vector3(0.01f, 0.01f, 0.01f));
        buttonCollider = (SphereCollider*)reference->GetComponent(SphereCollider::GetType());
    }
    static void Toggle(string buttonText)
    {
        int lastPage = ((Buttons::buttons[buttonsType].size() + 5 - 1) / 5) - 1;
        if (buttonText == "PreviousPage")
        {
            pageNumber--;
            if (pageNumber < 0)
            {
                pageNumber = lastPage;
            }
        }
        else
        {
            if (buttonText == "NextPage")
            {
                pageNumber++;
                if (pageNumber > lastPage)
                {
                    pageNumber = 0;
                }
            }
            else
            {
                ButtonInfo* target = GetIndex(buttonText);
                if (target != nullptr)
                {
                    if (target->isTogglable)
                    {
                        target->enabled = !target->enabled;
                        if (target->enabled)
                        {
                            if (target->enableMethod != nullptr)
                            {
                                target->enableMethod();
                            }
                        }
                        else
                        {
                            if (target->disableMethod != nullptr)
                            {
                                target->disableMethod();
                            }
                        }
                    }
                    else
                    {
                        if (target->method != nullptr)
                        {
                            target->method();
                        }
                    }
                }
            }
        }
        RecreateMenu();
    }
};
