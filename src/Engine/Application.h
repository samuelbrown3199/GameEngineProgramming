#include <memory>
#include <vector>

namespace myengine
{
	class Entity;

	class Application
	{
	private:
		Application();

		std::vector<std::shared_ptr<Entity>> entities;

	public:
		static std::shared_ptr<Application> Initialise();
		void Start();

		std::shared_ptr<Entity> AddEntity();
	};
}