#pragma once

#ifdef VIOLET_PLATFORM_WINDOWS

// declare that this will be defined outside our dll.
extern Violet::Application* Violet::CreateApplication();

int main(int argc, char** argv)
{
	Violet::Log::Init();
	VIOLET_CORE_WARN( "Init Core Log!" );
	VIOLET_WARN( "Init Client Log!" );
	VIOLET_TRACE( "Init Client Log!" );

	auto _app = Violet::CreateApplication();
	_app->Run();
	delete _app;
}
#endif