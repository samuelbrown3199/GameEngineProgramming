#include <memory>

namespace myengine
{
	class Application
	{
	private:
		Application();

	public:
		static std::shared_ptr<Application> Initialise();
		void Start();
	};
}