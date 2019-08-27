#include <sample.hh>
#include <results/option.hh>

namespace {{cookiecutter.namespace}} {

namespace {
results::option<std::string> hello() {
  return results::make_some<std::string>("hello from a ");
}
}

std::string public_function() {
  return hello().map([](auto s) { return s + "public function"; }).unwrap();
}

} // namespace {{cookiecutter.namespace}}
