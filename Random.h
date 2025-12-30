#pragma once
#include <BNMIncludes.hpp>

namespace System {
	class Random : public BNM::IL2CPP::Il2CppObject
	{
		public:
		static BNM::Class StaticClass() {
			return BNM::Class("System", "Random", BNM::Image("mscorlib.dll"));
		}
		
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> static T MBIG() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("MBIG");
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32 */
		static void set_MBIG(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("MBIG");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> static T MSEED() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("MSEED");
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32 */
		static void set_MSEED(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("MSEED");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> static T MZ() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("MZ");
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32 */
		static void set_MZ(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("MZ");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T _inext() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("_inext");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32 */
		void set__inext(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("_inext");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T _inextp() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("_inextp");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32 */
		void set__inextp(int value) {
			static BNM::Field<int> __bnm__field__ = StaticClass().GetField("_inextp");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Int32[] */
		template <typename T = BNM::Structures::Mono::Array<BNM::IL2CPP::Il2CppObject*>*> T _seedArray() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("_seedArray");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Int32[] */
		void set__seedArray(BNM::Structures::Mono::Array<BNM::IL2CPP::Il2CppObject*>* value) {
			static BNM::Field<BNM::Structures::Mono::Array<BNM::IL2CPP::Il2CppObject*>*> __bnm__field__ = StaticClass().GetField("_seedArray");
			__bnm__field__.SetInstance((BNM::IL2CPP::Il2CppObject*)this);
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Random */
		template <typename T = System::Random*> static T t_threadRandom() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("t_threadRandom");
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Random */
		static void set_t_threadRandom(System::Random* value) {
			static BNM::Field<System::Random*> __bnm__field__ = StaticClass().GetField("t_threadRandom");
			__bnm__field__.Set(value);
		}
		/* @brief Orig Type: System.Random */
		template <typename T = System::Random*> static T s_globalRandom() {
			static BNM::Field<T> __bnm__field__ = StaticClass().GetField("s_globalRandom");
			return __bnm__field__();
		}
		/* @param value Orig Type: System.Random */
		static void set_s_globalRandom(System::Random* value) {
			static BNM::Field<System::Random*> __bnm__field__ = StaticClass().GetField("s_globalRandom");
			__bnm__field__.Set(value);
		}
		
		/* @brief Orig Type: System.Double */
		template <typename T = double> T Sample() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Sample", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T InternalSample() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("InternalSample", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> static T GenerateSeed() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("GenerateSeed", 0);
			return __bnm__method__();
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> static T GenerateGlobalSeed() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("GenerateGlobalSeed", 0);
			return __bnm__method__();
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T Next() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Next", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T GetSampleForLargeRange() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("GetSampleForLargeRange", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T Next_1(int minValue, int maxValue) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Next", 2);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](minValue, maxValue);
		}
		/* @brief Orig Type: System.Int32 */
		template <typename T = int> T Next_2(int maxValue) {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("Next", 1);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this](maxValue);
		}
		/* @brief Orig Type: System.Double */
		template <typename T = double> T NextDouble() {
			static BNM::Method<T> __bnm__method__ = StaticClass().GetMethod("NextDouble", 0);
			return __bnm__method__[(BNM::IL2CPP::Il2CppObject*)this]();
		}
		
	};
}
