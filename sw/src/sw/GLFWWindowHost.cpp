#include "sw/GLFWWindowHost.h"

namespace sw {

	///===== Constructors =====///

	GLFWWindowHost::GLFWWindowHost(const Size& size, const std::string& title) :
			m_Size(size), m_Title(title) {

		m_Handle = glfwCreateWindow(m_Size.w, m_Size.h, m_Title.c_str(), NULL, NULL);

		if (!m_Handle) {
			Application::fatalError("Failed to open GLFW window.");
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		Application::current().addWindow(this);

		glfwMakeContextCurrent(m_Handle);

		glfwSetWindowUserPointer(m_Handle, this);

		glfwSetKeyCallback(m_Handle, GLFWWindowHost::glfwKeyCallback);
		glfwSetWindowCloseCallback(m_Handle, GLFWWindowHost::glfwCloseCallback);
		glfwSetWindowSizeCallback(m_Handle, GLFWWindowHost::glfwSizeCallback);
		glfwSetWindowPosCallback(m_Handle, GLFWWindowHost::glfwPositionCallback);
		glfwSetWindowRefreshCallback(m_Handle, GLFWWindowHost::glfwRefreshCallback);

		GLenum err = glewInit();
		if (err != GLEW_OK) {
			Application::fatalError("GLEW init failed: \"" + std::string((char*)glewGetErrorString(err)) + "\".");
		}

		glClear(GL_COLOR_BUFFER_BIT);
	}

	GLFWWindowHost::~GLFWWindowHost() {
		close();
	}

	/// === Getters / Setters =====///

	GLFWwindow* GLFWWindowHost::getHandle() const {
		return m_Handle;
	}

	Size GLFWWindowHost::getSize() const {
		return m_Size;
	}

	void GLFWWindowHost::setSize(const Size& size) {
		m_Size = size;

		glfwSetWindowSize(m_Handle, size.w, size.h);
	}

	std::string GLFWWindowHost::getTitle() const {
		return m_Title;
	}

	void GLFWWindowHost::setTitle(const std::string& title) {
		m_Title = title;

		glfwSetWindowTitle(m_Handle, m_Title.c_str());
	}

	///===== Methods =====///

	bool GLFWWindowHost::shouldClose() const {
		return glfwWindowShouldClose(m_Handle) == GL_TRUE;
	}

	void GLFWWindowHost::close() {
		glfwDestroyWindow(m_Handle);
		Application::current().removeWindow(this);
	}

	void GLFWWindowHost::makeContextCurrent() const {
		glfwMakeContextCurrent(m_Handle);
	}

	void GLFWWindowHost::swapBuffers() const {
		glfwSwapBuffers(m_Handle);
	}

	///===== Callbacks =====///

	void GLFWWindowHost::keyPressedCallback(int key, int scancode, int action, int mods) {

	}

	void GLFWWindowHost::closeRequestedCallback() {
		close();
	}

	void GLFWWindowHost::sizeChangedCallback(int width, int height) {
		m_Size = Size(width, height);

		glViewport(0, 0, width, height);

		onSizeChanged();
	}

	void GLFWWindowHost::positionChangedCallback(int xpos, int ypos) {

	}

	void GLFWWindowHost::refreshCallback() {
		onRender();
	}

	///===== GLFW Callbacks =====///

	void GLFWWindowHost::glfwKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		reinterpret_cast<GLFWWindowHost*>(glfwGetWindowUserPointer(window))->keyPressedCallback(key, scancode, action, mods);
	}

	void GLFWWindowHost::glfwCloseCallback(GLFWwindow* window) {
		reinterpret_cast<GLFWWindowHost*>(glfwGetWindowUserPointer(window))->closeRequestedCallback();
	}

	void GLFWWindowHost::glfwSizeCallback(GLFWwindow* window, int width, int height) {
		reinterpret_cast<GLFWWindowHost*>(glfwGetWindowUserPointer(window))->sizeChangedCallback(width, height);
	}

	void GLFWWindowHost::glfwPositionCallback(GLFWwindow* window, int xpos, int ypos) {
		reinterpret_cast<GLFWWindowHost*>(glfwGetWindowUserPointer(window))->positionChangedCallback(xpos, ypos);
	}

	void GLFWWindowHost::glfwRefreshCallback(GLFWwindow* window) {
		reinterpret_cast<GLFWWindowHost*>(glfwGetWindowUserPointer(window))->refreshCallback();
	}

}