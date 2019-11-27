Action()
{

	int ID = 0;
	int maxID = 0;
	char buffer [128];
	
	char * serviceID;
	char * serviceName;
	
	srand(time(NULL));
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("Homepage", 
		"URL=http://{URL}:{port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t67.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/js/core/jqueryformplugin.js?_=1574684061114", ENDITEM, 
		LAST);

	web_add_header("A-IM", 
		"x-bm,gzip");


	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("login", 
		"URL=http://{URL}:{port}/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t71.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("UC1_TR1_LOGIN");

	web_add_header("Origin", 
		"http://{URL}:{port}");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(10);

	web_submit_data("/api/login", 
		"Action=http://{URL}:{port}/api/login", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=http://{URL}:{port}/login", 
		"Snapshot=t72.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=login", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=rememberMe", "Value=false", ENDITEM, 
		LAST);

	web_add_cookie("currentCompany=0; DOMAIN={URL}");

	web_add_cookie("currentUser={Login}; DOMAIN={URL}");

	web_add_cookie("PFLB.pre.login.link=null; DOMAIN={URL}");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_cookie("filterSetting="
		"%7B%22page%22%3A%22http%3A%2F%2F{URL}%3A{port}%2F%23tickets%3Fstate%3Dopened%26page%3D1%22%2C%22smho%22%3Anull%2C%22dateStart%22%3A%22%22%2C%22dateEnd%22%3A%22%22%2C%22cat1%22%3Anull%2C%22cat2%22%3Anull%2C%22cat3%22%3Anull%2C%22cat4%22%3Anull%2C%22theme%22%3Anull%2C%22engineer%22%3Anull%2C%22location%22%3Anull%2C%22division%22%3Anull%2C%22overdue%22%3Afalse%2C%22filters%22%3A%7B%22newCheckbox%22%3Atrue%2C%22appointedCheckbox%22%3Atrue%2C%22performedCheckbox%22%3Atrue%2C%22controlCheckbo"
		"x%22%3Atrue%7D%7D; DOMAIN={URL}");

	web_url("Homepage_2", 
		"URL=http://{URL}:{port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{URL}:{port}/login", 
		"Snapshot=t73.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("/api/checkLogin", 
		"URL=http://{URL}:{port}/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t74.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/user/info", 
		"URL=http://{URL}:{port}/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t75.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/ticket/countByState/4", 
		"URL=http://{URL}:{port}/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t76.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/ticket/countByState/", 
		"URL=http://{URL}:{port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t77.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"URL=http://{URL}:{port}/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t78.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	lr_end_transaction("UC1_TR1_LOGIN",LR_AUTO);

	lr_start_transaction("UC1_TR2_NEWINC");

	web_url("/api/user/catalog/node/0/children/", 
		"URL=http://{URL}:{port}/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t79.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC1_TR2_NEWINC",LR_AUTO);

	lr_think_time(10);

	lr_start_transaction("UC1_TR3_LOCATION");
	
	web_reg_save_param_json(
        "ParamName=allshopids",
        "QueryString=$..id",
        "SelectAll=Yes", 
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");

	web_url("/api/shops?q=&page=0", 
		"URL=http://{URL}:{port}/api/shops?q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t80.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/user/catalog/node/0/children/", 
		"URL=http://{URL}:{port}/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t81.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_param_sprintf("shopid",lr_paramarr_random("allshopids"));
	                         
	web_reg_save_param_json(
        "ParamName=allservicesIDs",
        "QueryString=$..services..id",
        "SelectAll=Yes", 
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");
	
	web_reg_save_param_json(
        "ParamName=allservicesNames",
        "QueryString=$..services..name",
        "SelectAll=Yes", 
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");
		
	web_url("/api/user/catalog/treeview?shopid={shopid}", 
		"URL=http://{URL}:{port}/api/user/catalog/treeview?shopid={shopid}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t82.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC1_TR3_LOCATION",LR_AUTO);

	maxID = atoi(lr_eval_string("{allservicesIDs_count}"));
	ID= 1 + rand() % (maxID);
	
	sprintf(buffer, "{allservicesIDs_%i}", ID);
	serviceID = lr_eval_string(buffer);
		
	sprintf(buffer, "{allservicesNames_%i}", ID);
	serviceName = lr_eval_string(buffer);
	
	
	lr_param_sprintf("serviceID",serviceID);
	lr_param_sprintf("serviceName",serviceName);

	lr_start_transaction("UC1_TR4_QUESTION");

	web_url("/api/user/catalog/node/191/children/", 
		"URL=http://{URL}:{port}/api/user/catalog/node/191/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t83.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/user/catalog/node/191/service/", 
		"URL=http://{URL}:{port}/api/user/catalog/node/191/service/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t84.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/user/catalog/breadcrumbs/191", 
		"URL=http://{URL}:{port}/api/user/catalog/breadcrumbs/191", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t85.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_json(
        "ParamName=numberOfElements",
        "QueryString=$.numberOfElements",
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");
	            
	web_url("/api/inventoryNumbers?serviceId={serviceID}&shopId={shopid}", 
		"URL=http://{URL}:{port}/api/inventoryNumbers?serviceId={serviceID}&shopId={shopid}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t86.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC1_TR4_QUESTION",LR_AUTO);
	
	lr_think_time(10);

	lr_start_transaction("UC1_TR5_INVNUMBER");
	
	if (atoi(lr_eval_string("{numberOfElements}")) > 0)
		{
		
			web_reg_save_param_json(
	        "ParamName=allInventoryNumbers",
	        "QueryString=$..id.*",
	        "SelectAll=Yes", 
	        SEARCH_FILTERS,
	        "Scope=Body",
	        "LAST");
			
		lr_param_sprintf("InventoryNumber",lr_paramarr_random("allInventoryNumbers"));
			
		}
	else
		{
		lr_param_sprintf("InventoryNumber","null");
		};

	web_url("/api/inventoryNumbers?shopId={shopid}&serviceId={serviceID}&serviceId={serviceID}&q=&page=0", 
		"URL=http://{URL}:{port}/api/inventoryNumbers?shopId={shopid}&serviceId={serviceID}&serviceId={serviceID}&q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t87.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC1_TR5_INVNUMBER",LR_AUTO);

	lr_start_transaction("UC1_TR6_ADDFILE");

	web_add_auto_header("Origin", 
		"http://{URL}:{port}");

	lr_think_time(10);
	
	web_reg_save_param_json(
        "ParamName=fileID",
        "QueryString=$..id",
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");

	web_submit_data("file", 
		"Action=http://{URL}:{port}/api/ticket/file/", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t88.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=files", "Value=dist_ru (2)(1).zip", "File=Yes", ENDITEM, 
		LAST);

	lr_end_transaction("UC1_TR6_ADDFILE",LR_AUTO);

	lr_think_time(10);

		

	lr_start_transaction("UC1_TR7_CREATE");

	web_custom_request("/api/ticket/", 
		"URL=http://{URL}:{port}/api/ticket/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t89.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"BodyBinary={\"text\":\"{testtext}\"," 
					"\"header\":\"\{serviceName}\"," 
					"\"ticketStateId\":0," 
					"\"serviceId\":\"{serviceID}\"," 
					"\"files\":[{fileID}],\"inventoryNumberId\":\"{InventoryNumber}\",\"shopId\":\"{shopid}\"}",
		LAST);

	lr_end_transaction("UC1_TR7_CREATE",LR_AUTO);

	lr_start_transaction("UC1_TR8_OKBUTTON");

	web_revert_auto_header("Origin");

	web_revert_auto_header("X-Requested-With");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(10);

	web_url("{URL}:{port}_3", 
		"URL=http://{URL}:{port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t90.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("/api/checkLogin", 
		"URL=http://{URL}:{port}/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t91.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/user/info", 
		"URL=http://{URL}:{port}/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t92.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/ticket/countByState/4", 
		"URL=http://{URL}:{port}/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t93.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/ticket/countByState/", 
		"URL=http://{URL}:{port}/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t94.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC1_TR8_OKBUTTON",LR_AUTO);

	lr_think_time(10);

	lr_start_transaction("UC1_TR9_LOGOUT");

	web_url("/api/logout", 
		"URL=http://{URL}:{port}/api/logout", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t95.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("/login", 
		"URL=http://{URL}:{port}/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t96.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC1_TR9_LOGOUT",LR_AUTO);

	return 0;
}