#pragma once

#ifdef V_PLATFORM_WINDOWS

// declare that this will be defined outside our dll.
extern Violet::Application* Violet::CreateApplication();

int main(int argc, char** argv)
{
	auto _app = Violet::CreateApplication();
	_app->Run();
	delete _app;
}
#endif