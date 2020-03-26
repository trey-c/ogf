# Ocicat GUI Framework

> Currently in pre-alpha Research & Development (Aka. not suitable for production code yet)

`ogf` is an open source, lightweight, multi-platform GUI framework with a focus on modern graphics and scalability.

### Features

* 6 extendable widgets
* Supports gl
* Supports xcb
* Supports win32

### Example

```cpp
using namespace Ogf;

auto application = Core::Application::shared(argc, argv);

auto window = new Gui::Window("Demo Application", application);
auto button = new Gui::Label("Button", window);

button.on_click += [&](Button &b) {
    b.label().set_text("Button Clicked");
};

window.on_quit += [&]() {
    application->exit();
};

window.show_all();

return application->exec();
```

For a much better example, check out the [demo](demo/) application.

### Installing/Building

```bash
meson setup build -Dwerror=false
cd build
ninja
```

See the [README](ogf/README) file in the ogf/ source tree for more information. 

### License

`ogf` is licensed under the GNU Lesser General Public License, version 2.1 - See the [LICENSE](LICENSE) file for details.
