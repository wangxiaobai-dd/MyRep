#include <iostream>
#include <string>

using namespace std;
    class Web
    {
    public:
        // base_url is optional
        Web(const std::string& base_url);
        ~Web();

        static void go_home();

        static std::string home_url();
        static void set_home_url(const std::string& url);

        std::string url() const;
        void set_url(const std::string& url);
        std::string resolve_url(const std::string& uri);

        // doing reload if uri is empty
        std::string load(const std::string& uri);
    };
