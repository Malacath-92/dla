from conan import ConanFile


class ProxyPDF(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps"

    def requirements(self):
        self.requires("catch2/3.7.1")
