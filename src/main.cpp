#include <pybind11/pybind11.h>

#include <string>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int add(int i, int j) { return i + j; }

struct Pet {
  Pet(const std::string& name) : name(name) {}
  void setName(const std::string& name_) { name = name_; }
  const std::string& getName() const { return name; }

  std::string name;
};

namespace py = pybind11;

PYBIND11_MODULE(pybind_demo, m) {
  m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: pybind_demo

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

  m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc",
        py::arg("i"), py::arg("j"));

  m.def(
      "subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");
  py::class_<Pet>(m, "Pet")
      .def(py::init<const std::string&>())
      .def("setName", &Pet::setName)
      .def("getName", &Pet::getName)
      .def("__repr__", [](const Pet& a) { return "<example.Pet named '" + a.name + "'>"; });

#ifdef VERSION_INFO
  m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
  m.attr("__version__") = "dev";
#endif
}