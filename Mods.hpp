#pragma once

#include <utility>
#include "XRInput.hpp"
#include "BNMResolve.hpp"
#include "PhotonResolve.hpp"
//#include "SDK/Includes/GorillaGameManager.h"
#include "SDK/Includes/GorillaLocomotion/Player.h"
/*#include "SDK/Includes/GorillaTagger.h"
#include "SDK/Includes/GorillaTagManager.h"
#include "SDK/Includes/GorillaParent.h"
#include "SDK/Includes/VRRig.h"
#include "SDK/Includes/GorillaNetworking/CosmeticsController.h"
#include "SDK/Includes/GorillaNetworking/GorillaComputer.h"
#include "SDK/Includes/GorillaNetworking/PhotonNetworkController.h"*/
#include "SDK/Includes/PlayFab/PlayFabClientAPI.h"
#include "SDK/Includes/PlayFab.ClientModels/ItemInstance.h"
#include "SDK/Includes/PlayFab.ClientModels/GetUserInventoryRequest.h"
#include "SDK/Includes/PlayFab.ClientModels/GetUserInventoryResult.h"
//#include "SDK/Includes/HalloweenGhostChaser.h"
#include "SDK/Includes/PlayFab/PlayFabSettings.h"
#include "httplib.h"
#include "GorillaLocomotion.hpp"
#include "json.hpp"

//#include "SDK/Includes/HitTargetWithScoreCounter.h"
/*#include "SDK/Includes/GorillaSurfaceOverride.h"
#include "SDK/Includes/ControllerInputPoller.h"
#include "SDK/Includes/VRMap.h"*/
#include "random"
#include "GUI/Buttons.hpp"
//#include "SDK/Includes/GorillaPlayerScoreboardLine.h"
#include "Random.h"

using namespace BNM;
using namespace Structures::Unity;
using namespace Structures::Mono;
using namespace UnityEngine;

static Il2CppObject fdkdf[]
        {

        };
static Room* maxplayers;
static GameObject* PlatL;
static bool PlatLonce = false;
static GameObject* PlatR;
static bool PlatRonce = false;
static Vector3 normal2;
static Vector3 vel1;
static Vector3 vel2;
static float dist2;
static int layers;
static bool LeftClose2;
static bool DoOnce2;
static TextAnchor anchor = TextAnchor::UpperLeft;
static int currentAnchor = 0;
static GameObject* PlatformL;
static GameObject* PlatformR;
static GameObject* GunSphere;
static GameObject* vube;
static GameObject* ueacon;
static GameObject* cubo;
static float maxD2;
static GameObject* waterbox;
static bool once = false;
static int color = 0;
static vector<int> params = {75};
static vector<float> params2 = {1.f};
static System::Random* _random = new System::Random;
static Color strobeColors[] =
        {
                Color::red, Color::yellow, Color::green, Color::cyan, Color::blue, Color::magenta
        };
static vector<string> names =
        {
                "<color=red><size=9999>██████████████</size></color>"
                "<color=blue><size=9999>██████████████</size></color>"
                "<color=yellow><size=9999>██████████████</size></color>"
                "<color=green><size=9999>██████████████</size></color>"
        };
static string name = "COLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU";
static string name2 = "COLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\nCOLOSSAL CHEAT MENU COLOSSAL CHEAT MENU\n";

class ModsThing {
public:

    static void Mosa() {
        GorillaLocomotion::Player::get_Instance()->set_maxJumpSpeed(7.5f);
    }

    static void Coke() {
        GorillaLocomotion::Player::get_Instance()->set_maxJumpSpeed(8.5f);
    }

    static void Pixi() {
        GorillaLocomotion::Player::get_Instance()->set_maxJumpSpeed(9.5f);
    }

    static void RCoke() {
        if (XRInput::GetBoolFeature(GripButton, Right)) {
            GorillaLocomotion::Player::get_Instance()->set_maxJumpSpeed(8.5f);
        }
    }

    static void RPixi() {
        if (XRInput::GetBoolFeature(GripButton, Right)) {
            GorillaLocomotion::Player::get_Instance()->set_maxJumpSpeed(9.5f);
        }
    }

    static void LCoke() {
        if (XRInput::GetBoolFeature(GripButton, Left)) {
            GorillaLocomotion::Player::get_Instance()->set_maxJumpSpeed(8.5f);
        }
    }

    static void LPixi() {
        if (XRInput::GetBoolFeature(GripButton, Left)) {
            GorillaLocomotion::Player::get_Instance()->set_maxJumpSpeed(9.5f);
        }
    }

    static void LegMod() {
        if (GameObject::Find(
                "Global/GorillaParent/GorillaVRRigs/Gorilla Player Networked(Clone)/rig/body/shoulder.R/")->GetTransform()->GetLocalPosition().y !=
            0.f) {
            Vector3 localPosition = GameObject::Find(
                    "Global/GorillaParent/GorillaVRRigs/Gorilla Player Networked(Clone)/rig/body/shoulder.L/")->GetTransform()->GetLocalPosition();
            Vector3 localPosition2 = GameObject::Find(
                    "Global/GorillaParent/GorillaVRRigs/Gorilla Player Networked(Clone)/rig/body/shoulder.R/")->GetTransform()->GetLocalPosition();
            GameObject::Find(
                    "Global/GorillaParent/GorillaVRRigs/Gorilla Player Networked(Clone)/rig/body/shoulder.L/")->GetTransform()->SetLocalPosition(
                    Vector3(localPosition2.x, 0.f, localPosition2.z));
            GameObject::Find(
                    "Global/GorillaParent/GorillaVRRigs/Gorilla Player Networked(Clone)/rig/body/shoulder.R/")->GetTransform()->SetLocalPosition(
                    Vector3(localPosition.x, 0.f, localPosition.z));
        }
    }

    /*static void BreakNametags() {
        if (!once) {
            PhotonNetwork::GetLocalPlayer()->SetNickname(name2);
            GorillaNetworking::GorillaComputer::instance()->set_currentName(name);
            GorillaNetworking::GorillaComputer::instance()->set_savedName(name);
            PlayerPrefs::SetString("GorillaLocomotion.PlayerName", name2);
            once = true;
        } else {
            once = false;
        }
    }*/
    static void Disconnect() {
        PhotonNetwork::Disconnect();
    }
    static void JoinRandom() {
        PhotonNetwork::JoinRandomRoom();
    }
    static void BDisconnect() {
        if (XRInput::GetBoolFeature(SecondaryButton, Right)) {
            PhotonNetwork::Disconnect();
        }
    }
    static void YJoinRandom() {
        if (XRInput::GetBoolFeature(SecondaryButton, Left)) {
            PhotonNetwork::JoinRandomRoom();
        }
    }
    static void GrowArms()
    {
        if (XRInput::GetBoolFeature(TriggerButton, Right))
        {
            GameObject::Find("GorillaPlayer")->GetTransform()->SetLocalScale(GameObject::Find("GorillaPlayer")->GetTransform()->GetLocalScale() + Vector3(0.01, 0.01, 0.01));
        }
        if (XRInput::GetBoolFeature(TriggerButton, Left))
        {
            GameObject::Find("GorillaPlayer")->GetTransform()->SetLocalScale(GameObject::Find("GorillaPlayer")->GetTransform()->GetLocalScale() - Vector3(0.01, 0.01, 0.01));
        }
    }
    static void JoinDiscord()
    {
        Application::OpenUrl("https://discord.gg/pqDAkaUdXt");
    }
    static void QuitGame()
    {
        Application::Quit();
    }
    static void DisableQuitBox()
    {
        GameObject::Find("QuitBox")->SetActive(false);
    }
    static void DisableNetworkTriggers()
    {
        GameObject::Find("Networking Trigger")->SetActive(false);
    }
    static void LongArms()
    {
        GameObject::Find("GorillaPlayer")->GetTransform()->SetLocalScale(Vector3(1.3f, 1.3f, 1.3f));
    }
    static void MassiveLongArms()
    {
        GameObject::Find("GorillaPlayer")->GetTransform()->SetLocalScale(Vector3(1.7f, 1.7f, 1.7f));
    }
    static void SteamLongArms()
    {
        GameObject::Find("GorillaPlayer")->GetTransform()->SetLocalScale(Vector3(1.2f, 1.2f, 1.2f));
    }
    static void ShortArms()
    {
        GameObject::Find("GorillaPlayer")->GetTransform()->SetLocalScale(Vector3(0.7f, 0.7f, 0.7f));
    }
    static void ResetArms()
    {
        GameObject::Find("GorillaPlayer")->GetTransform()->SetLocalScale(Vector3(1.f, 1.f, 1.f));
    }
    static void CrashAllV1() {
        if (XRInput::GetBoolFeature(TriggerButton, Right)) {
            PhotonNetwork::DestroyAll();
            PhotonNetwork::DestroyAll();
            PhotonNetwork::DestroyAll();
            PhotonNetwork::DestroyAll();
            PhotonNetwork::DestroyAll();
        }
    }
    static void DestroyAll()
    {
        PhotonNetwork::DestroyAll();
    }
    static void CrashAllV2() {
        if (XRInput::GetBoolFeature(TriggerButton, Right)) {
            for (int i = 0; i < 100; i++) {
                for (Player *modder: PhotonNetwork::GetPlayerListOthers()) {
                    PhotonNetwork::DestroyPlayerObjects(modder);
                    PhotonNetwork::DestroyPlayerObjects(modder);
                    PhotonNetwork::DestroyPlayerObjects(modder);
                    PhotonNetwork::DestroyPlayerObjects(modder);
                    PhotonNetwork::DestroyPlayerObjects(modder);
                    PhotonNetwork::DestroyPlayerObjects(modder);
                    PhotonNetwork::DestroyPlayerObjects(modder);
                    PhotonNetwork::DestroyPlayerObjects(modder);
                }
            }
        }
    }
    static void NoTagFreeze()
    {
        GorillaLocomotion::Player::_instance()->set_disableMovement(false);
    }
    static void TagFreeze()
    {
        GorillaLocomotion::Player::_instance()->set_disableMovement(true);
    }
    static void Platforms1()
    {
        if (XRInput::GetBoolFeature(GripButton, Right))
        {
            if (PlatformR == nullptr)
            {
                PlatformR = GameObject::CreatePrimitive(PrimitiveType::Cube);
                auto* rend = (Renderer*)PlatformR->GetComponent(Renderer::GetType());
                rend->GetMaterial()->SetColor(Color(0.f, 0.7f, 1.f));
                rend->GetMaterial()->SetShader(Shader::Find("Unlit/Color"));
                PlatformR->GetTransform()->SetLocalScale(Vector3(0.3f, -0.02f, 0.25f));
                PlatformR->GetTransform()->SetPosition(GameObject::Find("RightHand Controller")->GetTransform()->GetPosition() + Vector3(0.f, -0.06f, 0.f));
                PlatformR->GetTransform()->SetRotation(GameObject::Find("RightHand Controller")->GetTransform()->GetRotation());
            }
        }
        else
        {
            if (PlatformR != nullptr)
            {
                GameObject::Destroy(PlatformR);
                PlatformR = nullptr;
            }
        }
        if (XRInput::GetBoolFeature(GripButton, Left))
        {
            if (PlatformL == nullptr)
            {
                PlatformL = GameObject::CreatePrimitive(PrimitiveType::Cube);
                auto* rend = (Renderer*)PlatformL->GetComponent(Renderer::GetType());
                rend->GetMaterial()->SetColor(Color(0.f, 0.7f, 1.f));
                rend->GetMaterial()->SetShader(Shader::Find("Unlit/Color"));
                PlatformL->GetTransform()->SetLocalScale(Vector3(0.3f, -0.02f, 0.25f));
                PlatformL->GetTransform()->SetPosition(GameObject::Find("LeftHand Controller")->GetTransform()->GetPosition() + Vector3(0.f, -0.06f, 0.f));
                PlatformL->GetTransform()->SetRotation(GameObject::Find("LeftHand Controller")->GetTransform()->GetRotation());
            }
        }
        else
        {
            if (PlatformL != nullptr)
            {
                GameObject::Destroy(PlatformL);
                PlatformL = nullptr;
            }
        }
    }
    static void PlatformSpam()
    {
        if (XRInput::GetBoolFeature(GripButton, Right))
        {
            PlatformR = GameObject::CreatePrimitive(PrimitiveType::Cube);
            auto* rend = (Renderer*)PlatformR->GetComponent(Renderer::GetType());
            rend->GetMaterial()->SetColor(Color(0.f, 0.7f, 1.f));
            GameObject::Destroy(PlatformR->GetComponent(Rigidbody::GetType()));
            GameObject::Destroy(PlatformR->GetComponent(Collider::GetType()));
            rend->GetMaterial()->SetShader(Shader::Find("Unlit/Color"));
            GameObject::Destroy(PlatformR->GetComponent(MeshCollider::GetType()));
            PlatformR->GetTransform()->SetLocalScale(Vector3(0.3f, -0.02f, 0.25f));
            PlatformR->GetTransform()->SetPosition(GameObject::Find("RightHand Controller")->GetTransform()->GetPosition());
            PlatformR->GetTransform()->SetRotation(GameObject::Find("RightHand Controller")->GetTransform()->GetRotation());
        }
        if (PlatformR != nullptr)
        {
            GameObject::Destroy(PlatformR, 1.f);
        }
        if (XRInput::GetBoolFeature(GripButton, Left))
        {
            GameObject::Destroy(PlatformL->GetComponent(Rigidbody::GetType()));
            GameObject::Destroy(PlatformL->GetComponent(Collider::GetType()));
            GameObject::Destroy(PlatformL->GetComponent(MeshCollider::GetType()));
            PlatformL = GameObject::CreatePrimitive(PrimitiveType::Cube);
            auto* rend = (Renderer*)PlatformL->GetComponent(Renderer::GetType());
            rend->GetMaterial()->SetShader(Shader::Find("Unlit/Color"));
            rend->GetMaterial()->SetColor(Color(0.f, 0.7f, 1.f));
            PlatformL->GetTransform()->SetLocalScale(Vector3(0.3f, -0.02f, 0.25f));
            PlatformL->GetTransform()->SetPosition(GameObject::Find("LeftHand Controller")->GetTransform()->GetPosition());
            PlatformL->GetTransform()->SetRotation(GameObject::Find("LeftHand Controller")->GetTransform()->GetRotation());
        }
        if (PlatformL != nullptr)
        {
            GameObject::Destroy(PlatformL, 1.f);
        }
    }
    static void Frozone()
    {
        if (XRInput::GetBoolFeature(GripButton, Right))
        {
            PlatformR = GameObject::CreatePrimitive(PrimitiveType::Cube);
            auto* rend = (Renderer*)PlatformR->GetComponent(Renderer::GetType());
            rend->GetMaterial()->SetColor(Color(0.f, 0.7f, 1.f));
            GameObject::Destroy(PlatformR->GetComponent(Rigidbody::GetType()));
            GameObject::Destroy(PlatformR->GetComponent(Collider::GetType()));
            rend->GetMaterial()->SetShader(Shader::Find("Unlit/Color"));
            GameObject::Destroy(PlatformR->GetComponent(MeshCollider::GetType()));
            PlatformR->GetTransform()->SetLocalScale(Vector3(0.3f, -0.02f, 0.25f));
            PlatformR->GetTransform()->SetPosition(GameObject::Find("RightHand Controller")->GetTransform()->GetPosition() + Vector3(0.f, -0.05f, 0.f));
            PlatformR->GetTransform()->SetRotation(GameObject::Find("RightHand Controller")->GetTransform()->GetRotation());
            //auto* gso = (GlobalNamespace::GorillaSurfaceOverride*)PlatformR->AddComponent(GlobalNamespace::GorillaSurfaceOverride::StaticClass().GetMonoType());
            //gso->set_overrideIndex(61);
        }
        if (PlatformR != nullptr)
        {
            GameObject::Destroy(PlatformR, 1.f);
        }
        if (XRInput::GetBoolFeature(GripButton, Left))
        {
            GameObject::Destroy(PlatformL->GetComponent(Rigidbody::GetType()));
            GameObject::Destroy(PlatformL->GetComponent(Collider::GetType()));
            PlatformL = GameObject::CreatePrimitive(PrimitiveType::Cube);
            auto* rend = (Renderer*)PlatformL->GetComponent(Renderer::GetType());
            rend->GetMaterial()->SetShader(Shader::Find("Unlit/Color"));
            rend->GetMaterial()->SetColor(Color(0.f, 0.7f, 1.f));
            PlatformL->GetTransform()->SetLocalScale(Vector3(0.3f, -0.02f, 0.25f));
            PlatformL->GetTransform()->SetPosition(GameObject::Find("LeftHand Controller")->GetTransform()->GetPosition() + Vector3(0.f, -0.05f, 0.f));
            PlatformL->GetTransform()->SetRotation(GameObject::Find("LeftHand Controller")->GetTransform()->GetRotation());
            //auto* gso = (GlobalNamespace::GorillaSurfaceOverride*)PlatformL->AddComponent(GlobalNamespace::GorillaSurfaceOverride::StaticClass().GetMonoType());
            //gso->set_overrideIndex(61);
        }
        if (PlatformL != nullptr)
        {
            GameObject::Destroy(PlatformL, 1.f);
        }
    }
    static void InvisPlatforms()
    {
        if (XRInput::GetBoolFeature(GripButton, Right))
        {
            if (PlatformR == nullptr)
            {
                PlatformR = GameObject::CreatePrimitive(PrimitiveType::Cube);
                auto* rend = (Renderer*)PlatformR->GetComponent(Renderer::GetType());
                GameObject::Destroy(rend);
                PlatformR->GetTransform()->SetLocalScale(Vector3(0.3f, -0.02f, 0.25f));
                PlatformR->GetTransform()->SetPosition(GameObject::Find("RightHand Controller")->GetTransform()->GetPosition() + Vector3(0.f, -0.06f, 0.f));
                PlatformR->GetTransform()->SetRotation(GameObject::Find("RightHand Controller")->GetTransform()->GetRotation());
            }
        }
        else
        {
            if (PlatformR != nullptr)
            {
                GameObject::Destroy(PlatformR);
                PlatformR = nullptr;
            }
        }
        if (XRInput::GetBoolFeature(GripButton, Left))
        {
            if (PlatformL == nullptr)
            {
                PlatformL = GameObject::CreatePrimitive(PrimitiveType::Cube);
                auto* rend = (Renderer*)PlatformL->GetComponent(Renderer::GetType());
                GameObject::Destroy(rend);
                PlatformL->GetTransform()->SetLocalScale(Vector3(0.3f, -0.02f, 0.25f));
                PlatformL->GetTransform()->SetPosition(GameObject::Find("LeftHand Controller")->GetTransform()->GetPosition() + Vector3(0.f, -0.06f, 0.f));
                PlatformL->GetTransform()->SetRotation(GameObject::Find("LeftHand Controller")->GetTransform()->GetRotation());
            }
        }
        else
        {
            if (PlatformL != nullptr)
            {
                GameObject::Destroy(PlatformL);
                PlatformL = nullptr;
            }
        }
    }
    static void SpherePlatforms()
    {
        if (XRInput::GetBoolFeature(GripButton, Right))
        {
            if (PlatformR == nullptr)
            {
                PlatformR = GameObject::CreatePrimitive(PrimitiveType::Sphere);
                auto* rend = (Renderer*)PlatformR->GetComponent(Renderer::GetType());
                rend->GetMaterial()->SetColor(Color(0.f, 0.7f, 1.f));
                rend->GetMaterial()->SetShader(Shader::Find("Unlit/Color"));
                PlatformR->GetTransform()->SetLocalScale(Vector3(0.333f, 0.333f, 0.333f));
                PlatformR->GetTransform()->SetPosition(GameObject::Find("RightHand Controller")->GetTransform()->GetPosition());
                PlatformR->GetTransform()->SetRotation(GameObject::Find("RightHand Controller")->GetTransform()->GetRotation());
            }
        }
        else {
            if (PlatformR != nullptr)
            {
                GameObject::Destroy(PlatformR);
                PlatformR = nullptr;
            }
        }
        if (XRInput::GetBoolFeature(GripButton, Left))
        {
            if (PlatformL == nullptr)
            {
                PlatformL = GameObject::CreatePrimitive(PrimitiveType::Sphere);
                auto* rend = (Renderer*)PlatformL->GetComponent(Renderer::GetType());
                rend->GetMaterial()->SetColor(Color(0.f, 0.7f, 1.f));
                rend->GetMaterial()->SetShader(Shader::Find("Unlit/Color"));
                PlatformL->GetTransform()->SetLocalScale(Vector3(0.333f, 0.333f, 0.333f));
                PlatformL->GetTransform()->SetPosition(GameObject::Find("LeftHand Controller")->GetTransform()->GetPosition());
                PlatformL->GetTransform()->SetRotation(GameObject::Find("LeftHand Controller")->GetTransform()->GetRotation());
            }
        }
        else
        {
            if (PlatformL != nullptr)
            {
                GameObject::Destroy(PlatformL);
                PlatformL = nullptr;
            }
        }
    }
    static void Fly() {
        static auto inst = GorillaLocomotion::Player::get_Instance<GorillaLocomotion::Player*>();
        static auto rb = inst->playerRigidBody<Rigidbody*>();

        Vector2 leftJoystick = XRInput::GetVector2Feature(Vector2Feature::Primary2DAxis, Controller::Left);
        Vector2 rightJoystick = XRInput::GetVector2Feature(Vector2Feature::Primary2DAxis, Controller::Right);

        Vector3 inputDirection = Vector3(leftJoystick.x, rightJoystick.y, leftJoystick.y);
        Vector3 playerForward = inst->bodyCollider<Collider*>()->GetTransform()->GetForward();
        playerForward.y = 0;
        Vector3 playerRight = inst->bodyCollider<Collider*>()->GetTransform()->GetRight();
        playerRight.y = 0;

        Vector3 velocity = inputDirection.x * playerRight + rightJoystick.y * Vector3::up + inputDirection.z * playerForward;
        velocity *= reinterpret_cast<Behaviour*>(inst)->GetTransform()->GetLocalScale().x * 15.f;
        rb->SetVelocity(Vector3::Lerp(rb->GetVelocity(), velocity, 0.12875f));
    }
    static void PlatformGun() {
        if (XRInput::GetBoolFeature(GripButton, Right))
        {
            RaycastHit hit;
            if (Physics::Raycast(GameObject::Find("RightHand Controller")->GetTransform()->GetPosition(), -GameObject::Find("RightHand Controller")->GetTransform()->GetUp(), hit)) {
                if (GunSphere == nullptr)
                {
                    GunSphere = GameObject::CreatePrimitive(PrimitiveType::Sphere);
                    GunSphere->GetTransform()->SetLocalScale(Vector3(0.1f, 0.1f, 0.1f));
                    auto *rend = (Renderer *) GunSphere->GetComponent(Renderer::GetType());
                    rend->GetMaterial()->SetShader(Shader::Find("Unlit/Color"));
                    rend->GetMaterial()->SetColor(Color(0.f, 0.7f, 1.f));
                    GameObject::Destroy(GunSphere->GetComponent(BoxCollider::GetType()));
                    GameObject::Destroy(GunSphere->GetComponent(Rigidbody::GetType()));
                    GameObject::Destroy(GunSphere->GetComponent(Collider::GetType()));
                }
                GunSphere->GetTransform()->SetPosition(hit.point);
                if (XRInput::GetBoolFeature(TriggerButton, Right))
                {
                    PlatformL = GameObject::CreatePrimitive(PrimitiveType::Cube);
                    GameObject::Destroy(PlatformL->GetComponent(Rigidbody::GetType()));
                    GameObject::Destroy(PlatformL->GetComponent(Collider::GetType()));
                    GameObject::Destroy(PlatformL->GetComponent(MeshCollider::GetType()));
                    auto* rend32 = (Renderer*)PlatformL->GetComponent(Renderer::GetType());
                    rend32->GetMaterial()->SetColor(Color(0.f, 0.7f, 1.f));
                    PlatformL->GetTransform()->SetLocalScale(Vector3(0.3f, -0.02f, 0.25f));
                    PlatformL->GetTransform()->SetPosition(GunSphere->GetTransform()->GetPosition());
                    PlatformL->GetTransform()->SetRotation(GunSphere->GetTransform()->GetRotation());
                }
                if (PlatformL != nullptr)
                {
                    GameObject::Destroy(PlatformL, 1.f);
                }
            }
        }
        else
        {
            if (GunSphere != nullptr)
            {
                GameObject::Destroy(GunSphere);
                GunSphere = nullptr;
            }
        }
    }
    static void CrashGun() {
        if (XRInput::GetBoolFeature(GripButton, Right))
        {
            RaycastHit hit;
            if (Physics::Raycast(GameObject::Find("RightHand Controller")->GetTransform()->GetPosition(), -GameObject::Find("RightHand Controller")->GetTransform()->GetUp(), hit)) {
                if (GunSphere == nullptr)
                {
                    GunSphere = GameObject::CreatePrimitive(PrimitiveType::Sphere);
                    GunSphere->GetTransform()->SetLocalScale(Vector3(0.1f, 0.1f, 0.1f));
                    auto *rend = (Renderer *) GunSphere->GetComponent(Renderer::GetType());
                    rend->GetMaterial()->SetShader(Shader::Find("Unlit/Color"));
                    rend->GetMaterial()->SetColor(Color(0.f, 0.7f, 1.f));
                    GameObject::Destroy(GunSphere->GetComponent(BoxCollider::GetType()));
                    GameObject::Destroy(GunSphere->GetComponent(Rigidbody::GetType()));
                    GameObject::Destroy(GunSphere->GetComponent(Collider::GetType()));
                }
                GunSphere->GetTransform()->SetPosition(hit.point);
                if (XRInput::GetBoolFeature(TriggerButton, Right))
                {
                    auto* c = (Collider*)hit.GetCollider();
                    if (c->GetComponentInParent(PhotonView::GetType(), false))
                    {
                        auto* plz = (PhotonView*)c;
                        auto* owner = (Player*)plz->GetOwner();
                        PhotonNetwork::DestroyPlayerObjects(owner);
                        PhotonNetwork::DestroyPlayerObjects(owner);
                        PhotonNetwork::DestroyPlayerObjects(owner);
                        PhotonNetwork::DestroyPlayerObjects(owner);
                        PhotonNetwork::DestroyPlayerObjects(owner);
                        PhotonNetwork::DestroyPlayerObjects(owner);
                    }
                }
            }
        }
        else
        {
            if (GunSphere != nullptr)
            {
                GameObject::Destroy(GunSphere);
                GunSphere = nullptr;
            }
        }
    }
    /*static void LoudTaps()
    {
        GlobalNamespace::GorillaTagger::_instance()->set_handTapVolume(999.f);
    }
    static void SilentTaps()
    {
        GlobalNamespace::GorillaTagger::_instance()->set_handTapVolume(0.f);
    }
    static void ResetTaps()
    {
        GlobalNamespace::GorillaTagger::_instance()->set_handTapVolume(0.1f);
    }
    static void SlideControl()
    {
        GorillaLocomotion::Player::_instance()->set_slideControl(99.f);
    }
    static void SmallSlideControl()
    {
        GorillaLocomotion::Player::_instance()->set_slideControl(0.005f);
    }
    static void NoSlideControl()
    {
        GorillaLocomotion::Player::_instance()->set_slideControl(0.f);
    }
    static void ResetSlideControl()
    {
        GorillaLocomotion::Player::_instance()->set_slideControl(0.001f);
    }*/
    static void PullModTest() {
        if (XRInput::GetBoolFeature(GripButton, Left))
        {
            if (GorillaLocomotion::Player::_instance()->wasLeftHandTouching())
            {
                auto velo = (Vector3)GorillaLocomotionPlayer::GetInstance()->GetPlayerRigidbody()->GetVelocity();
                GorillaLocomotionPlayer::GetInstance()->GetTransform()->SetPosition(GorillaLocomotionPlayer::GetInstance()->GetTransform()->GetPosition() + Vector3(velo.x / 10.f, velo.y / 10.f, velo.z / 10.f));
            }
        }
    }
    static void ZeroGravity()
    {
        auto* rigid = (Rigidbody*)GameObject::Find("GorillaPlayer")->GetComponent(Rigidbody::GetType());
        rigid->SetUseGravity(false);
    }
    static void Gravity()
    {
        auto* rigid = (Rigidbody*)GameObject::Find("GorillaPlayer")->GetComponent(Rigidbody::GetType());
        rigid->SetUseGravity(true);
    }
    static void SpeedUp()
    {
        Time::SetTimeScale(3.f);
    }
    static void Normal()
    {
        Time::SetTimeScale(1.f);
    }
    static void SlowDown()
    {
        Time::SetTimeScale(.5f);
    }
    static void TestFly() {
        if (XRInput::GetBoolFeature(TriggerButton, Left)) {
            GorillaLocomotionPlayer::GetInstance()->GetTransform()->SetPosition(GorillaLocomotionPlayer::GetInstance()->GetTransform()->GetPosition() + GorillaLocomotionPlayer::GetInstance()->GetHeadCollider()->GetTransform()->GetForward() * Time::GetDeltaTime() * 15.f);
            GorillaLocomotionPlayer::GetInstance()->GetPlayerRigidbody()->SetVelocity(Vector3::zero);
        }
    }
    static void ControllerFly() {
        if (XRInput::GetBoolFeature(TriggerButton, Left)) {
            GorillaLocomotionPlayer::GetInstance()->GetTransform()->SetPosition(GorillaLocomotionPlayer::GetInstance()->GetTransform()->GetPosition() + GorillaLocomotionPlayer::GetInstance()->GetRightHandTransform()->GetForward() * Time::GetDeltaTime() * 15.f);
            GorillaLocomotionPlayer::GetInstance()->GetPlayerRigidbody()->SetVelocity(Vector3::zero);
        }
    }
    static void UpAndDown()
    {
        auto* Rigidbod = (Rigidbody*)GameObject::Find("GorillaPlayer")->GetComponent(Rigidbody::GetType());
        if (XRInput::GetBoolFeature(TriggerButton, Right))
        {
            Rigidbod->AddForce(Vector3(0.f, 50.f, 0.f), Acceleration);
        }
        if (XRInput::GetBoolFeature(TriggerButton, Left))
        {
            Rigidbod->AddForce(Vector3(0.f, -50.f, 0.f), Acceleration);
        }
    }
    static void SetMaster()
    {
        PhotonNetwork::SetMasterClient(PhotonNetwork::GetLocalPlayer());
    }
    static void RigSpamMtnBeta()
    {
        PhotonNetwork::Instantiate("gorillaprefabs/gorillaplayeractual", GameObject::Find("GorillaPlayer")->GetTransform()->GetPosition(), GameObject::Find("GorillaPlayer")->GetTransform()->GetRotation(), 0, nullptr);
    }
    static void RigSpam()
    {
        PhotonNetwork::Instantiate("gorillaprefabs/Gorilla Player Networked", GameObject::Find("GorillaPlayer")->GetTransform()->GetPosition(), GameObject::Find("GorillaPlayer")->GetTransform()->GetRotation(), 0, nullptr);
    }
    static void RigSpamFangames()
    {
        PhotonNetwork::Instantiate("PhotonVR/Player", GameObject::Find("GorillaPlayer")->GetTransform()->GetPosition(), GameObject::Find("GorillaPlayer")->GetTransform()->GetRotation(), 0, nullptr);
    }
    static void Noclip() {
        for (auto* mesh : GameObject::FindObjectsOfType(MeshCollider::GetType())->ToVector())
        {
            auto* ddd = (MeshCollider*)mesh;
            if (XRInput::GetBoolFeature(TriggerButton, Right))
            {
                ddd->SetEnabled(false);
            }
            else
            {
                ddd->SetEnabled(true);
            }
        }
    }
    static void NoPlatsAllowed() {
        if (PlatformL != nullptr || PlatformR != nullptr)
        {
            GameObject::Destroy(PlatformL);
            PlatformL = nullptr;
            GameObject::Destroy(PlatformR);
            PlatformR = nullptr;
        }
    }
    /*static void SlowAll() {
        if (XRInput::GetBoolFeature(TriggerButton, Left))
        {
            for (Player *modding: PhotonNetwork::GetPlayerListOthers())
            {
                auto* photonView = (PhotonView*)GlobalNamespace::GorillaGameManager::instance()->FindVRRigForPlayer(modding);
                photonView->RPC("SetTaggedTime", modding, nullptr);
            }
        }
    }
    static void VibrateAll() {
        if (XRInput::GetBoolFeature(TriggerButton, Left))
        {
            for (Player *modding: PhotonNetwork::GetPlayerListOthers())
            {
                auto* photonView = (PhotonView*)GlobalNamespace::GorillaGameManager::instance()->FindVRRigForPlayer(modding);
                photonView->RPC("SetJoinTaggedTime", modding, nullptr);
            }
        }
    }
    static void MatAll() {
        auto things = GameObject::FindObjectsOfType(GlobalNamespace::GorillaTagManager::StaticClass().GetMonoType());
        if (XRInput::GetBoolFeature(GripButton, Right))
        {
            for (auto i : things->ToVector())
            {
                auto *col = (GlobalNamespace::GorillaTagManager *) i;
                for (int j = 0; j < things->GetSize(); j++)
                {
                    col[j].ClearInfectionState();
                }
                GlobalNamespace::GorillaGameManager::instance()->set_checkCooldown(0.f);
                col->set_tagCoolDown(0.f);
            }
        }
    }
    static void Chams()
    {
        for (auto i: GameObject::FindObjectsOfType(GlobalNamespace::VRRig::StaticClass().GetMonoType())->ToVector()) {
            if (vube == nullptr) {
                auto *col = (GlobalNamespace::VRRig *) i;
                auto* mainsk = (SkinnedMeshRenderer*)col->mainSkin();
                mainsk->GetMaterial()->SetColor(Color(0.f, 0.7f, 1.f));
                mainsk->GetMaterial()->SetShader(Shader::Find("GUI/Text Shader"));
            }
        }
    }
    static void AntiModerator()
    {
        auto things = GameObject::FindObjectsOfType(GlobalNamespace::VRRig::StaticClass().GetMonoType());
        for (auto i: things->ToVector()) {
            auto *col = (GlobalNamespace::VRRig *) i;
            if (col->concatStringOfCosmeticsAllowed()->str().find("LBAAK."))
            {
                PhotonNetwork::Disconnect();
            }
        }
    }
    static void AntiAdmin() {
        auto things = GameObject::FindObjectsOfType(
                GlobalNamespace::VRRig::StaticClass().GetMonoType());
        for (auto i: things->ToVector()) {
            auto *col = (GlobalNamespace::VRRig *) i;
            if (col->concatStringOfCosmeticsAllowed()->str().find("LBAAD.")) {
                PhotonNetwork::Disconnect();
            }
        }
    }
    static void NoFingerMovement()
    {
        GlobalNamespace::ControllerInputPoller::instance()->set_leftControllerGripFloat(0.f);
        GlobalNamespace::ControllerInputPoller::instance()->set_leftControllerIndexFloat(0.f);
        GlobalNamespace::ControllerInputPoller::instance()->set_rightControllerGripFloat(0.f);
        GlobalNamespace::ControllerInputPoller::instance()->set_rightControllerIndexFloat(0.f);
        GlobalNamespace::ControllerInputPoller::instance()->set_leftControllerPrimaryButton(false);
        GlobalNamespace::ControllerInputPoller::instance()->set_leftControllerPrimaryButtonTouch(false);
        GlobalNamespace::ControllerInputPoller::instance()->set_leftControllerSecondaryButton(false);
        GlobalNamespace::ControllerInputPoller::instance()->set_leftControllerSecondaryButtonTouch(false);
        GlobalNamespace::ControllerInputPoller::instance()->set_rightControllerPrimaryButton(false);
        GlobalNamespace::ControllerInputPoller::instance()->set_rightControllerPrimaryButtonTouch(false);
        GlobalNamespace::ControllerInputPoller::instance()->set_rightControllerSecondaryButton(false);
        GlobalNamespace::ControllerInputPoller::instance()->set_rightControllerSecondaryButtonTouch(false);
    }
    static void EndGameSpam() {
        auto things = GameObject::FindObjectsOfType(
                GlobalNamespace::GorillaTagManager::StaticClass().GetMonoType());
        if (XRInput::GetBoolFeature(TriggerButton, Right)) {
            for (auto i: things->ToVector()) {
                auto *col = (GlobalNamespace::GorillaTagManager *) i;
                col->SetisCurrentlyTag(false);
            }
        }
    }
    static void TagAll() {
        auto things = GameObject::FindObjectsOfType(
                GlobalNamespace::GorillaTagManager::StaticClass().GetMonoType());
        if (XRInput::GetBoolFeature(TriggerButton, Right)) {
            for (auto i: things->ToVector()) {
                auto *col = (GlobalNamespace::GorillaTagManager *) i;
                for (Player* play : PhotonNetwork::GetPlayerListOthers())
                {
                    col->AddInfectedPlayer(play);
                    col->UpdateState();
                }
            }
        }
    }
    static void NoHandTapDelay()
    {
        GlobalNamespace::GorillaTagger::_instance()->set_tapCoolDown(0.f);
    }
    static void FixTapDelay()
    {
        GlobalNamespace::GorillaTagger::_instance()->set_tapCoolDown(0.2f);
    }
    static void BecomeOblixo()
    {
        PhotonNetwork::GetLocalPlayer()->SetNickname("OBLIXO");
        PlayerPrefs::SetString("playerName", "OBLIXO");
        GlobalNamespace::GorillaTagger::_instance()->UpdateColor(0.f, 0.5f, 1.f);
        PlayerPrefs::Save();
    }
    static void UnMuteAll()
    {
        auto things = GameObject::FindObjectsOfType(GlobalNamespace::VRRig::StaticClass().GetMonoType());
        if (XRInput::GetBoolFeature(TriggerButton, Right)) {
            for (auto i: things->ToVector()) {
                auto *col = (GlobalNamespace::VRRig *) i;
                col->set_muted(false);
            }
        }
    }

    static void SlipMonke()
    {
        auto things = GameObject::FindObjectsOfType(GlobalNamespace::GorillaSurfaceOverride::StaticClass().GetMonoType());
        if (XRInput::GetBoolFeature(TriggerButton, Right)) {
            for (auto i: things->ToVector()) {
                auto *col = (GlobalNamespace::GorillaSurfaceOverride *) i;
                col->set_overrideIndex(61);
            }
        }
    }
    static void GripMonke()
    {
        auto things = GameObject::FindObjectsOfType(GlobalNamespace::GorillaSurfaceOverride::StaticClass().GetMonoType());
        if (XRInput::GetBoolFeature(TriggerButton, Right)) {
            for (auto i: things->ToVector()) {
                auto *col = (GlobalNamespace::GorillaSurfaceOverride *) i;
                col->set_overrideIndex(0);
            }
        }
    }*/
    static void ApexNameTag()
    {
        PhotonNetwork::GetLocalPlayer()->SetNickname("<color=#1ABAFD>APEX MENU USER</color>");
        PhotonNetwork::GetLocalPlayer()->SetUserId("<color=#05A4E8>.gg/8RxXrATDSS</color>");
        PlayerPrefs::Save();
    }
    static void NoName()
    {
        PhotonNetwork::GetLocalPlayer()->SetNickname(" ");
        PlayerPrefs::SetString("playerName", " ");
        PlayerPrefs::Save();
    }
    static void EarlyAccessPack()
    {
    }
    static void EU()
    {
        PhotonNetwork::ConnectToRegion("eu");
    }
    static void US()
    {
        PhotonNetwork::ConnectToRegion("us");
    }
    static void USW()
    {
        PhotonNetwork::ConnectToRegion("usw");
    }
    static void DisableAFKKick()
    {
        //GorillaNetworking::PhotonNetworkController::instance()->set_disableAFKKick(true);
    }
    static void EnableAFKKick()
    {
        //GorillaNetworking::PhotonNetworkController::instance()->set_disableAFKKick(true);
    }
    static void DisconnectPlayfab()
    {
        PhotonNetwork::Disconnect();
        //GorillaNetworking::PhotonNetworkController::instance()->set_currentState(0);
        PlayFab::PlayFabClientAPI::ForgetAllCredentials();
    }
    static void MagentaSky()
    {
        GameObject* newSky = GameObject::Find("night sky/newsky (1)");
        auto* m = (MeshRenderer*)newSky->GetComponent(MeshRenderer::GetType());
        m->GetMaterial()->SetShader(Shader::Find("Standard"));
        m->GetMaterial()->SetColor(Color::magenta);
    }
    static void RedSky()
    {
        GameObject* newSky = GameObject::Find("night sky/newsky (1)");
        auto* m = (MeshRenderer*)newSky->GetComponent(MeshRenderer::GetType());
        m->GetMaterial()->SetShader(Shader::Find("Standard"));
        m->GetMaterial()->SetColor(Color::red);
    }
    static void CyanSky()
    {
        GameObject* newSky = GameObject::Find("night sky/newsky (1)");
        auto* m = (MeshRenderer*)newSky->GetComponent(MeshRenderer::GetType());
        m->GetMaterial()->SetShader(Shader::Find("Standard"));
        m->GetMaterial()->SetColor(Color::cyan);
    }
    static void GreenSky()
    {
        GameObject* newSky = GameObject::Find("night sky/newsky (1)");
        auto* m = (MeshRenderer*)newSky->GetComponent(MeshRenderer::GetType());
        m->GetMaterial()->SetShader(Shader::Find("Standard"));
        m->GetMaterial()->SetColor(Color::green);
    }
    static void LowQuality()
    {
        QualitySettings::SetMasterTextureLimit(999999);
    }
    static void NoLowQuality()
    {
        QualitySettings::SetMasterTextureLimit(0);
    }
    /*static void SummonLucy()
    {
        auto* chase = (GlobalNamespace::HalloweenGhostChaser*)GameObject::Find("Halloween Ghost/FloatingChaseSkeleton")->GetComponent(GlobalNamespace::HalloweenGhostChaser::StaticClass().GetMonoType());
        chase->set_timeGongStarted(Time::GetTime());
        chase->set_currentState(4);
        chase->set_isSummoned(true);
    }
    static void UnlockComp()
    {
        GorillaNetworking::GorillaComputer::instance()->CompQueueUnlockButtonPress();
    }
    static void MaxPlayers()
    {
        GlobalNamespace::GorillaGameManager::instance()->set_roomSize(50);
        GorillaNetworking::PhotonNetworkController::instance()->set_isRoomFull(false);
        maxplayers->SetMaxPlayers(50);
    }
    static void RPCCrashAll() {
        for (Player *play: PhotonNetwork::GetPlayerListOthers()) {
            auto *pv = (PhotonView *) GlobalNamespace::GorillaGameManager::instance()->returnPhotonView();
            if (XRInput::GetBoolFeature(BoolFeature::GripButton, Controller::Right)) {
                pv->RPC("UpdatePlayerCosmetic", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("UpdatePlayerCosmetic", play, nullptr);
                pv->RPC("UpdatePlayerCosmetic", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("UpdatePlayerCosmetic", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("UpdatePlayerCosmetic", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("UpdatePlayerCosmetic", play, nullptr);
                pv->RPC("UpdatePlayerCosmetic", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("UpdatePlayerCosmetic", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("UpdatePlayerCosmetic", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("UpdatePlayerCosmetic", play, nullptr);
                pv->RPC("UpdatePlayerCosmetic", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
                pv->RPC("UpdatePlayerCosmetic", play, nullptr);
                pv->RPC("RequestCosmetics", play, nullptr);
            }
        }
    }
    static void SpamTargets()
    {
        auto things = GameObject::FindObjectsOfType(GlobalNamespace::HitTargetWithScoreCounter::StaticClass().GetMonoType());
        if (XRInput::GetBoolFeature(TriggerButton, Right)) {
            for (auto i: things->ToVector()) {
                auto *col = (GlobalNamespace::HitTargetWithScoreCounter *) i;
                col->set_hitCooldownTime(0);
                col->TargetHit();
                col->set_digitsChange(true);
            }
        }
    }
    static void SpinHeadX()
    {
        auto* vrmap = (GlobalNamespace::VRMap*)GlobalNamespace::GorillaTagger::_instance()->myVRRig<GlobalNamespace::VRRig*>()->head<GlobalNamespace::VRMap*>();
        vrmap->set_trackingRotationOffset(vrmap->trackingRotationOffset() + Vector3(15.f, 0.f, 0.f));
    }
    static void SpinHeadY()
    {
        auto* vrig = (GlobalNamespace::VRRig*)GlobalNamespace::GorillaTagger::_instance()->myVRRig();
        auto* vrmap = (GlobalNamespace::VRMap*)vrig->head();
        vrmap->set_trackingRotationOffset(vrmap->trackingRotationOffset() + Vector3(0.f, 15.f, 0.f));
    }
    static void SpinHeadZ()
    {
        auto* vrig = (GlobalNamespace::VRRig*)GlobalNamespace::GorillaTagger::_instance()->myVRRig();
        auto* vrmap = (GlobalNamespace::VRMap*)vrig->head();
        vrmap->set_trackingRotationOffset(vrmap->trackingRotationOffset() + Vector3(0.f, 0.f, 15.f));
    }
    static void BreakHead()
    {
        auto* vrig = (GlobalNamespace::VRRig*)GlobalNamespace::GorillaTagger::_instance()->myVRRig();
        auto* vrmap = (GlobalNamespace::VRMap*)vrig->head();
        vrmap->set_trackingRotationOffset(Vector3(0.f, 180.f, 0.f));
    }
    static void FixHead()
    {
        auto* vrig = (GlobalNamespace::VRRig*)GlobalNamespace::GorillaTagger::_instance()->myVRRig();
        auto* vrmap = (GlobalNamespace::VRMap*)vrig->head();
        vrmap->set_trackingRotationOffset(Vector3(0.f, 0.f, 0.f));
    }
    static void ShinyRocks()
    {
        GorillaNetworking::CosmeticsController::instance()->set_gotMyDaily(false);
        GorillaNetworking::CosmeticsController::instance()->set_secondsUntilTomorrow(0);
        GorillaNetworking::CosmeticsController::instance()->set_checkedDaily(false);
    }
    static void EasySpeedBoost(float maxJumpSpeed, float jumpMultiplier, bool V1, bool V2)
    {
        if (V1)
        {
            GorillaLocomotion::Player::_instance()->set_maxJumpSpeed(maxJumpSpeed);
            GorillaLocomotion::Player::_instance()->set_jumpMultiplier(jumpMultiplier);
        }
        if (V2)
        {
            GlobalNamespace::GorillaGameManager::instance()->set_slowJumpLimit(maxJumpSpeed);
            GlobalNamespace::GorillaGameManager::instance()->set_slowJumpMultiplier(jumpMultiplier);
        }
    }
    static void AntiReport() {
        auto vrig = GameObject::FindObjectsOfType(GlobalNamespace::VRRig::StaticClass().GetMonoType());
        auto gpsl = GameObject::FindObjectsOfType(GlobalNamespace::GorillaPlayerScoreboardLine::StaticClass().GetMonoType());
        for (auto vrigs: vrig->ToVector()) {
            for (auto gpsls: gpsl->ToVector()) {
                auto *col = (GlobalNamespace::GorillaPlayerScoreboardLine *) gpsls;
                auto *coler = (GlobalNamespace::VRRig *) vrigs;
                auto *e = (Transform *) col;
                if (Vector3::Distance(coler->rightHandTransform<Transform *>()->GetPosition(), e->GetPosition()) < 1.f || Vector3::Distance(coler->leftHandTransform<Transform *>()->GetPosition(), e->GetPosition()) < 1.f)
                {
                    PhotonNetwork::Disconnect();
                }
            }
        }
    }*/
    static void SpawnPrefabHand(string prefabName)
    {
        if (XRInput::GetBoolFeature(GripButton, Right))
        {
            try
            {
                PhotonNetwork::Instantiate(prefabName, GorillaLocomotionPlayer::GetInstance()->GetRightHandTransform()->GetPosition(), GorillaLocomotionPlayer::GetInstance()->GetRightHandTransform()->GetRotation(), 0, nullptr);
            }
            catch (exception s){}
        }
    }
    static void SpawnPrefabGun(string prefabName) {
        if (XRInput::GetBoolFeature(GripButton, Right))
        {
            RaycastHit hit;
            if (Physics::Raycast(GorillaLocomotionPlayer::GetInstance()->GetRightHandTransform()->GetPosition(), -GorillaLocomotionPlayer::GetInstance()->GetRightHandTransform()->GetUp(), hit)) {
                if (GunSphere == nullptr)
                {
                    GunSphere = GameObject::CreatePrimitive(PrimitiveType::Sphere);
                    GunSphere->GetTransform()->SetLocalScale(Vector3(0.1f, 0.1f, 0.1f));
                    auto *rend = (Renderer *) GunSphere->GetComponent(Renderer::GetType());
                    rend->GetMaterial()->SetShader(Shader::Find("Unlit/Color"));
                    rend->GetMaterial()->SetColor(Color(0.f, 0.7f, 1.f));
                    GameObject::Destroy(GunSphere->GetComponent(BoxCollider::GetType()));
                    GameObject::Destroy(GunSphere->GetComponent(Rigidbody::GetType()));
                    GameObject::Destroy(GunSphere->GetComponent(Collider::GetType()));
                }
                GunSphere->GetTransform()->SetPosition(hit.point);
                if (XRInput::GetBoolFeature(TriggerButton, Right))
                {
                    try
                    {
                        PhotonNetwork::Instantiate(prefabName, GunSphere->GetTransform()->GetPosition(), GunSphere->GetTransform()->GetRotation(), 0, nullptr);
                    }
                    catch (exception s){}
                }
            }
        }
        else
        {
            if (GunSphere != nullptr)
            {
                GameObject::Destroy(GunSphere);
                GunSphere = nullptr;
            }
        }
    }
    static void BigNameNetworkPlayer()
    {
        int i = 0;
        i = (i + 1) % names.size();
        PhotonNetwork::GetLocalPlayer()->SetNickname(names[i]);
        PhotonNetwork::GetLocalPlayer()->SetUserId(names[i]);
    }
    static void noonre() {
    }
    static void Auth()
    {
    }
    static void Asuth()
    {
    }
    static void Quit()
    {
        Application::Quit();
        GameObject::Destroy(GameObject::Find("GorillaPlayer"));
        GameObject::Destroy(GameObject::Find("Photon Manager"));
    }

    static void KickAll()
    {
        if (XRInput::GetBoolFeature(PrimaryButton, Right))
        {
            for (Player *player: PhotonNetwork::GetPlayerListOthers())
            {
                GorillaNetworking::PhotonNetworkController::instance()->friendIDList()->Add(player->GetUserId());
                GlobalNamespace::GorillaGameManager::instance()->returnPhotonView<PhotonView*>()->RPC("JoinPubWithFreinds", player, nullptr);
                PhotonNetwork::SendAllOutgoingCommands();
            }
        }
    }

    static void CosmeticX()
    { //haha loser
    }
    static void LowQualityMic()
    {
        auto* rec = (Recorder*)GameObject::Find("Photon Manager")->GetComponent(Recorder::GetType());
        rec->SetBitrate(6000);
    }
    static void ResetMic()
    {
        auto* rec = (Recorder*)GameObject::Find("Photon Manager")->GetComponent(Recorder::GetType());
        rec->SetBitrate(30000);
    }

};
