#pragma once
#include <string>
#include <sdl/SDL.h>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	virtual ~Display();
	bool IsClosed();
	void Update();
	void Clear(float r, float g, float b, float a);
	float GetAspectRatio();
protected:
private :
	Display(const Display& rhs);
	Display& operator =(const Display& rhs);

	
	
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;
	
	float m_width;
	float m_height;
	
};

