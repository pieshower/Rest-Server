
#ifndef SERVER.H
#define SERVER.H



#include "httplib.h"
#include "json.hpp"

#include "server.h"



int serverPort__ = 8077;



namespace RestServer
{

	void handleGetMode(const httplib::Request &req, httplib::Response &res)
	{
		nlohmann::json jValue;
		std::string modeString = "REST";

		jValue["mode"] = modeString;

		res.set_content(jValue.dump(), "application/json");
	}

	int main(int argc, char **argv)
	{

		httplib::Server svr_;

		std::cout << "Starting REST server at port " << serverPort__ << std::endl;

		if (!svr_.is_valid())
		{
			std::cout << "Rest server has an error..." << std::endl;
			return -1;
		}

		svr_.Get("/stop", [&](const httplib::Request &req, httplib::Response &res)
		{
			std::cout << "Rest server is stopping..." << std::endl;
			(void)req;
			(void)res;
			svr_.stop();
		});

		svr_.set_error_handler([](const httplib::Request &req, httplib::Response &res)
		{
			const char *fmt = "<p>Error Status: <span style='color:red;'>%d</span></p>";

			char buf[BUFSIZ];

			if (res.body.length() > 4)
			{
				snprintf(buf, sizeof(buf), "<p>Error Status: <span style='color:red;'>%d</span></p><p>Message: %s</p>", res.status, res.body.c_str());
			}
			else
			{
				snprintf(buf, sizeof(buf), fmt, res.status);
			}

			res.set_content(buf, "text/html");
		});


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------


		svr_.Get("/HEY", [](const httplib::Request &req, httplib::Response &res)
		{

            nlohmann::json jsonRes;

            std::string responce = "Hello, Bitch!";

            jsonRes["responce"] = responce;

            res.set_content(jsonRes.dump(), "application/json");
            
        });


		svr_.Post("/get_mode", [](const httplib::Request &req, httplib::Response &res)
		{
			handleGetMode(req, res);
		});


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

        svr_.listen("0.0.0.0", serverPort__);

		std::cout << "Quitting REST server at port " << serverPort__ << std::endl;

		return 0;

	}

}


#endif SERVER.H

