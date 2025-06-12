from conan import ConanFile
from conan.tools.cmake import cmake_layout


class StMFC(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("wxwidgets/[>=3.2.6]")

    def layout(self):
        cmake_layout(self)
