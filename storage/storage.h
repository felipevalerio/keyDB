#include <map>
#include <string>

namespace storage {

	class storage {

		public:
			void put(std::map<std::string, std::string>, std::string, std::string);

		
		public:
			void del(std::string, std::map<std::string, std::string>);

		
		public:
			void get_all(std::map<std::string, std::string>);
	};
}
