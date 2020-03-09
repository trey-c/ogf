# Ocicat GUI Framework

`ogf` is an open source, lightweight, multi-platform GUI framework with a focus on modern graphics and scalability.

### Example
```cpp
using namespace Ogf;

auto application = Core::Application::shared(argc, argv);

auto window = Widget::Window("Demo Application", application);
auto button = Widget::Label("Button", window);

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

See the [README](ogf/README) file in the ogf/ source tree for more information. 

### License

`ogf` is licensed under the GNU Lesser General Public License, version 2.1 - See the [LICENSE](LICENSE) file for details.
