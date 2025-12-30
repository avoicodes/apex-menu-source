#include "BNMResolve.hpp"

struct GorillaLocomotionPlayer;
struct Surface;

struct GorillaLocomotionPlayer : BNM::UnityEngine::MonoBehaviour
{
    static Class GetClass()
    {
        return Class("GorillaLocomotion", "Player", Image("Assembly-CSharp.dll"));
    }

    static MonoType* GetType()
    {
        static MonoType *type = GetClass().GetMonoType();
        return type;
    }

    static GorillaLocomotionPlayer* _instance()
    {
        static Field<GorillaLocomotionPlayer*> instance = GetClass().GetField("_instance");
        return instance();
    }

    static GorillaLocomotionPlayer* GetInstance()
    {
        static Method<GorillaLocomotionPlayer*> Instance = GetClass().GetMethod("get_Instance");
        return Instance();
    }

    SphereCollider* GetHeadCollider()
    {
        static Field<SphereCollider*> headCollider = GetClass().GetField("headCollider");
        headCollider.SetInstance(this);
        return headCollider();
    }

    void SetHeadCollider(SphereCollider* pos)
    {
        static Field<SphereCollider*> setheadCollider = GetClass().GetField("headCollider");
        setheadCollider.SetInstance(this);
        setheadCollider.Set(pos);
    }

    Il2CppObject* GetBodyCollider() //Original Type: CapsuleCollider
    {
        static Field<Il2CppObject*> bodyCollider = GetClass().GetField("bodyCollider");
        bodyCollider.SetInstance(this);
        return bodyCollider();
    }

    void SetBodyCollider(Il2CppObject* pos) //Original Type: CapsuleCollider
    {
        static Field<Il2CppObject*> setbodyCollider = GetClass().GetField("bodyCollider");
        setbodyCollider.SetInstance(this);
        setbodyCollider.Set(pos);
    }

    Transform* GetLeftHandFollower()
    {
        static Field<Transform*> leftHandFollower = GetClass().GetField("leftHandFollower");
        leftHandFollower.SetInstance(this);
        return leftHandFollower();
    }

    void SetLeftHandFollower(Transform* pos)
    {
        static Field<Transform*> setleftHandFollower = GetClass().GetField("leftHandFollower");
        setleftHandFollower.SetInstance(this);
        setleftHandFollower.Set(pos);
    }

    Transform* GetRightHandFollower()
    {
        static Field<Transform*> rightHandFollower = GetClass().GetField("rightHandFollower");
        rightHandFollower.SetInstance(this);
        return rightHandFollower();
    }

    void SetRightHandFollower(Transform* pos)
    {
        static Field<Transform*> setrightHandFollower = GetClass().GetField("rightHandFollower");
        setrightHandFollower.SetInstance(this);
        setrightHandFollower.Set(pos);
    }

    Transform* GetRightHandTransform()
    {
        static Field<Transform*> rightHandTransform = GetClass().GetField("rightHandTransform");
        rightHandTransform.SetInstance(this);
        return rightHandTransform();
    }

    void SetRightHandTransform(Transform *pos)
    {
        static Field<Transform*> setrightHandTransform = GetClass().GetField("rightHandTransform");
        setrightHandTransform.SetInstance(this);
        setrightHandTransform.Set(pos);
    }

    Transform* GetLeftHandTransform()
    {
        static Field<Transform*> leftHandTransform = GetClass().GetField("leftHandTransform");
        leftHandTransform.SetInstance(this);
        return leftHandTransform();
    }

    void SetLeftHandTransform(Transform* pos)
    {
        static Field<Transform*> setleftHandTransform = GetClass().GetField("leftHandTransform");
        setleftHandTransform.SetInstance(this);
        setleftHandTransform.Set(pos);
    }

    Vector3 GetLastRightHandPosition()
    {
        static Field<Vector3> lastRightHandPosition = GetClass().GetField("lastRightHandPosition");
        lastRightHandPosition.SetInstance(this);
        return lastRightHandPosition();
    }

    void SetLastRightHandPosition(Vector3 pos)
    {
        static Field<Vector3> setlastRightHandPosition = GetClass().GetField("lastRightHandPosition");
        setlastRightHandPosition.SetInstance(this);
        setlastRightHandPosition.Set(pos);
    }

    Vector3 GetLastLeftHandPosition()
    {
        static Field<Vector3> lastLeftHandPosition = GetClass().GetField("lastLeftHandPosition");
        lastLeftHandPosition.SetInstance(this);
        return lastLeftHandPosition();
    }

    void SetLastLeftHandPosition(Vector3 pos)
    {
        static Field<Vector3> setlastLeftHandPosition = GetClass().GetField("lastLeftHandPosition");
        setlastLeftHandPosition.SetInstance(this);
        setlastLeftHandPosition.Set(pos);
    }

    Vector3 GetLastHeadPosition()
    {
        static Field<Vector3> lastHeadPosition = GetClass().GetField("lastHeadPosition");
        lastHeadPosition.SetInstance(this);
        return lastHeadPosition();
    }

    void SetLastHeadPosition(Vector3 pos)
    {
        static Field<Vector3> setlastHeadPosition = GetClass().GetField("lastHeadPosition");
        setlastHeadPosition.SetInstance(this);
        setlastHeadPosition.Set(pos);
    }

    Rigidbody* GetPlayerRigidbody()
    {
        static Field<Rigidbody*> playerRigidBody = GetClass().GetField("playerRigidBody");
        playerRigidBody.SetInstance(this);
        return playerRigidBody();
    }

    void SetPlayerRigidbody(Rigidbody* rig)
    {
        static Field<Rigidbody*> setplayerRigidbody = GetClass().GetField("playerRigidBody");
        setplayerRigidbody.SetInstance(this);
        setplayerRigidbody.Set(rig);
    }

    int GetVelocityHistorySize()
    {
        static Field<int> velocityHistorySize = GetClass().GetField("velocityHistorySize");
        velocityHistorySize.SetInstance(this);
        return velocityHistorySize();
    }

    void SetVelocityHistorySize(int size)
    {
        static Field<int> setvelocityHistorySize = GetClass().GetField("velocityHistorySize");
        setvelocityHistorySize.SetInstance(this);
        setvelocityHistorySize.Set(size);
    }

    float GetMaxArmLength()
    {
        static Field<float> maxArmLength = GetClass().GetField("maxArmLength");
        maxArmLength.SetInstance(this);
        return maxArmLength();
    }

    void SetMaxArmLength(float maxArmLength)
    {
        static Field<float> setmaxArmLength = GetClass().GetField("maxArmLength");
        setmaxArmLength.SetInstance(this);
        setmaxArmLength.Set(maxArmLength);
    }

    float GetUnStickDistance()
    {
        static Field<float> unStickDistance = GetClass().GetField("unStickDistance");
        unStickDistance.SetInstance(this);
        return unStickDistance();
    }

    void SetUnStickDistance(float unStickDistance)
    {
        static Field<float> setunStickDistance = GetClass().GetField("unStickDistance");
        setunStickDistance.SetInstance(this);
        setunStickDistance.Set(unStickDistance);
    }

    float GetVelocityLimit()
    {
        static Field<float> velocityLimit = GetClass().GetField("velocityLimit");
        velocityLimit.SetInstance(this);
        return velocityLimit();
    }

    void SetVelocityLimit(float velocityLimit)
    {
        static Field<float> setvelocityLimit = GetClass().GetField("velocityLimit");
        setvelocityLimit.SetInstance(this);
        setvelocityLimit.Set(velocityLimit);
    }

    float GetMaxJumpSpeed()
    {
        static Field<float> maxJumpSpeed = GetClass().GetField("maxJumpSpeed");
        maxJumpSpeed.SetInstance(this);
        return maxJumpSpeed();
    }

    void SetMaxJumpSpeed(float maxJumpSpeed)
    {
        static Field<float> setmaxJumpSpeed = GetClass().GetField("maxJumpSpeed");
        setmaxJumpSpeed.SetInstance(this);
        setmaxJumpSpeed.Set(maxJumpSpeed);
    }

    float GetJumpMultiplier()
    {
        static Field<float> jumpMultiplier = GetClass().GetField("jumpMultiplier");
        jumpMultiplier.SetInstance(this);
        return jumpMultiplier();
    }

    void SetJumpMultiplier(float jumpMultiplier)
    {
        static Field<float> setjumpMultiplier = GetClass().GetField("jumpMultiplier");
        setjumpMultiplier.SetInstance(this);
        setjumpMultiplier.Set(jumpMultiplier);
    }

    float GetMinimumRaycastDistance()
    {
        static Field<float> minimumRaycastDistance = GetClass().GetField("minimumRaycastDistance");
        minimumRaycastDistance.SetInstance(this);
        return minimumRaycastDistance();
    }

    void SetMinimumRaycastDistance(float minimumRaycastDistance)
    {
        static Field<float> setminimumRaycastDistance = GetClass().GetField("minimumRaycastDistance");
        setminimumRaycastDistance.SetInstance(this);
        setminimumRaycastDistance.Set(minimumRaycastDistance);
    }

    float GetDefaultSlideFactor()
    {
        static Field<float> defaultSlideFactor = GetClass().GetField("defaultSlideFactor");
        defaultSlideFactor.SetInstance(this);
        return defaultSlideFactor();
    }

    void SetDefaultSlideFactor(float slideFactor)
    {
        static Field<float> setdefaultSlideFactor = GetClass().GetField("defaultSlideFactor");
        setdefaultSlideFactor.SetInstance(this);
        setdefaultSlideFactor.Set(slideFactor);
    }

    float GetDefaultPrecision()
    {
        static Field<float> defaultPrecision = GetClass().GetField("defaultPrecision");
        defaultPrecision.SetInstance(this);
        return defaultPrecision();
    }

    void SetDefaultPrecision(float precision)
    {
        static Field<float> setdefaultPrecision = GetClass().GetField("defaultPrecision");
        setdefaultPrecision.SetInstance(this);
        setdefaultPrecision.Set(precision);
    }

    Array<Vector3*>* GetVelocityHistory()
    {
        static Field<Array<Vector3*>*> velocityHistory = GetClass().GetField("velocityHistory");
        velocityHistory.SetInstance(this);
        return velocityHistory();
    }

    void SetVelocityHistory(Array<Vector3*>* velocityHistory)
    {
        static Field<Array<Vector3*>*> setvelocityHistory = GetClass().GetField("velocityHistory");
        setvelocityHistory.SetInstance(this);
        setvelocityHistory.Set(velocityHistory);
    }

    int GetVelocityIndex()
    {
        static Field<int> velocityIndex = GetClass().GetField("velocityIndex");
        velocityIndex.SetInstance(this);
        return velocityIndex();
    }

    void SetVelocityIndex(int velocityIndex)
    {
        static Field<int> setvelocityIndex = GetClass().GetField("velocityIndex");
        setvelocityIndex.SetInstance(this);
        setvelocityIndex.Set(velocityIndex);
    }

    Vector3 GetCurrentVelocity()
    {
        static Field<Vector3> currentVelocity = GetClass().GetField("currentVelocity");
        currentVelocity.SetInstance(this);
        return currentVelocity();
    }

    void SetCurrentVelocity(Vector3 velocity)
    {
        static Field<Vector3> setcurrentVelocity = GetClass().GetField("currentVelocity");
        setcurrentVelocity.SetInstance(this);
        setcurrentVelocity.Set(velocity);
    }

    bool GetJumpHandIsLeft()
    {
        static Field<bool> jumpHandIsLeft = GetClass().GetField("jumpHandIsLeft");
        jumpHandIsLeft.SetInstance(this);
        return jumpHandIsLeft();
    }

    void SetJumpHandIsLeft(bool leftHanded)
    {
        static Field<bool> setjumpHandIsLeft = GetClass().GetField("jumpHandIsLeft");
        setjumpHandIsLeft.SetInstance(this);
        setjumpHandIsLeft.Set(leftHanded);
    }

    Vector3 GetLastPosition()
    {
        static Field<Vector3> lastPosition = GetClass().GetField("lastPosition");
        lastPosition.SetInstance(this);
        return lastPosition();
    }

    void SetLastPosition(Vector3 lastPos)
    {
        static Field<Vector3> setlastPosition = GetClass().GetField("lastPosition");
        setlastPosition.SetInstance(this);
        setlastPosition.Set(lastPos);
    }

    Vector3 GetRightHandOffset()
    {
        static Field<Vector3> rightHandOffset = GetClass().GetField("rightHandOffset");
        rightHandOffset.SetInstance(this);
        return rightHandOffset();
    }

    void SetRightHandOffset(Vector3 offset)
    {
        static Field<Vector3> setrightHandOffset = GetClass().GetField("rightHandOffset");
        setrightHandOffset.SetInstance(this);
        setrightHandOffset.Set(offset);
    }

    Vector3 GetLeftHandOffset()
    {
        static Field<Vector3> leftHandOffset = GetClass().GetField("leftHandOffset");
        leftHandOffset.SetInstance(this);
        return leftHandOffset();
    }

    void SetLeftHandOffset(Vector3 offset)
    {
        static Field<Vector3> setleftHandOffset = GetClass().GetField("leftHandOffset");
        setleftHandOffset.SetInstance(this);
        setleftHandOffset.Set(offset);
    }

    LayerMask* GetLocomotionEnabledLayers()
    {
        static Field<LayerMask*> locomotionEnabledLayers = GetClass().GetField("locomotionEnabledLayers");
        locomotionEnabledLayers.SetInstance(this);
        return locomotionEnabledLayers();
    }

    void SetLocomotionEnabledLayers(LayerMask* layers)
    {
        static Field<LayerMask*> setlocomotionEnabledLayers = GetClass().GetField("locomotionEnabledLayers");
        setlocomotionEnabledLayers.SetInstance(this);
        setlocomotionEnabledLayers.Set(layers);
    }

    bool GetWasLeftHandTouching()
    {
        static Field<bool> WasLeftHandTouching = GetClass().GetField("wasLeftHandTouching");
        WasLeftHandTouching.SetInstance(this);
        return WasLeftHandTouching();
    }

    void SetWasLeftHandTouching(bool wasTouching)
    {
        static Field<bool> setwasLeftHandTouching = GetClass().GetField("wasLeftHandTouching");
        setwasLeftHandTouching.SetInstance(this);
        setwasLeftHandTouching.Set(wasTouching);
    }

    bool GetWasRightHandTouching()
    {
        static Field<bool> wasrightHandTouching = GetClass().GetField("wasRightHandTouching");
        wasrightHandTouching.SetInstance(this);
        return wasrightHandTouching();
    }

    void SetWasRightHandTouching(bool wasTouching)
    {
        static Field<bool> setwasrightHandTouching = GetClass().GetField("wasRightHandTouching");
        setwasrightHandTouching.SetInstance(this);
        setwasrightHandTouching.Set(wasTouching);
    }

    bool GetDisableMovement()
    {
        static Field<bool> disableMovement = GetClass().GetField("disableMovement");
        disableMovement.SetInstance(this);
        return disableMovement();
    }

    void SetDisableMovement(bool disableMovement)
    {
        static Field<bool> setdisableMovement = GetClass().GetField("disableMovement");
        setdisableMovement.SetInstance(this);
        setdisableMovement.Set(disableMovement);
    }

    void InitializeValues()
    {
        static Method<void> initializeValues = GetClass().GetMethod("InitializeValues", 0);
        initializeValues[this]();
    }

    Transform* GetTransform()
    {
        static Method<Transform*> getTransform = GetClass().GetMethod("get_transform", 0);
        return getTransform[this]();
    }

    Vector3 CurrentLeftHandPosition()
    {
        static Method<Vector3> CurrentLeftHandPosition = GetClass().GetMethod("CurrentLeftHandPosition", 0);
        return CurrentLeftHandPosition[this]();
    }

    Vector3 CurrentRightHandPosition()
    {
        static Method<Vector3> CurrentRightHandPosition = GetClass().GetMethod("CurrentRightHandPosition", 0);
        return CurrentRightHandPosition[this]();
    }

    bool IterativeCollisionSphereCast(Vector3 startPosition, float sphereRadius, Vector3 movementVector, float precision, Vector3** endPosition, bool singleHand)
    {
        static Method<bool> IterativeCollisionSphereCast = GetClass().GetMethod("IterativeCollisionSphereCast", { "startPosition", "sphereRadius", "movementVector", "precision", "endPosition", "singleHand"});
        return IterativeCollisionSphereCast[this](startPosition, sphereRadius, movementVector, precision, endPosition, singleHand);
    }

    bool CollisionsSphereCast(Vector3 startPosition, float sphereRadius, Vector3 movementVector, float precision, Vector3** finalPosition, RaycastHit** hitInfo)
    {
        static Method<bool> CollisionsSphereCast = GetClass().GetMethod("CollisionsSphereCast", { "startPosition", "sphereRadius", "movementVector", "precision", "finalPosition", "hitInfo"});
        return CollisionsSphereCast[this](startPosition, sphereRadius, movementVector, precision, finalPosition, hitInfo);
    }

    bool IsHandTouching(bool forLeftHand)
    {
        static Method<bool> IsHandTouching = GetClass().GetMethod("IsHandTouching", 1);
        return IsHandTouching[this](forLeftHand);
    }

    void Turn(float degrees)
    {
        static Method<void> Turn = GetClass().GetMethod("Turn", 1);
        Turn[this](degrees);
    }

    void StoreVelocities()
    {
        static Method<void> StoreVelocities = GetClass().GetMethod("StoreVelocities", 0);
        StoreVelocities[this]();
    }
};

struct Surface : BNM::UnityEngine::MonoBehaviour
{
    static Class GetClass()
    {
        return Class("GorillaLocomotion", "Surface", Image("Assembly-CSharp.dll"));
    }

    static MonoType* GetType()
    {
        static MonoType *type = GetClass().GetMonoType();
        return type;
    }

    float GetSlipPercentage()
    {
        static Field<float> slipPercentage = GetClass().GetField("slipPercentage");
        slipPercentage.SetInstance(this);
        return slipPercentage();
    }

    void SetSlipPercentage(float percentage)
    {
        static Field<float> setslipPercentage = GetClass().GetField("slipPercentage");
        setslipPercentage.SetInstance(this);
        setslipPercentage.Set(percentage);
    }
};