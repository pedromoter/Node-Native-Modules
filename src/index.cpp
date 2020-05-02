#include <napi.h>
#include <string>
#include "greeting.h"

Napi::String greetHello(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

std::string user = (std::string) info[0].ToString();


  std::string result = helloUser(user);

  return Napi::String::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "greetHello"),
              Napi::Function::New(env, greetHello));
  return exports;
}

NODE_API_MODULE(greet, Init)