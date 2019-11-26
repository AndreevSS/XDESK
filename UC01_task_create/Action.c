Action()
{

	int test,i = 0;
	int maxI = 0;
	char BuffPar [128];
	
	char * serviceID;
	char * serviceName;
	
	srand(time(NULL));
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("learning2.pflb.ru:56902", 
		"URL=http://learning2.pflb.ru:56902/", 
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
		"URL=http://learning2.pflb.ru:56902/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t71.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("UC1_TR1_LOGIN");

	web_add_header("Origin", 
		"http://learning2.pflb.ru:56902");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(14);

	web_submit_data("login_2", 
		"Action=http://learning2.pflb.ru:56902/api/login", 
		"Method=POST", 
		"TargetFrame=", 
		"Referer=http://learning2.pflb.ru:56902/login", 
		"Snapshot=t72.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=login", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=rememberMe", "Value=false", ENDITEM, 
		LAST);

	web_add_cookie("currentCompany=0; DOMAIN=learning2.pflb.ru");

	web_add_cookie("currentUser={Login}; DOMAIN=learning2.pflb.ru");

	web_add_cookie("PFLB.pre.login.link=null; DOMAIN=learning2.pflb.ru");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_cookie("filterSetting="
		"%7B%22page%22%3A%22http%3A%2F%2Flearning2.pflb.ru%3A56902%2F%23tickets%3Fstate%3Dopened%26page%3D1%22%2C%22smho%22%3Anull%2C%22dateStart%22%3A%22%22%2C%22dateEnd%22%3A%22%22%2C%22cat1%22%3Anull%2C%22cat2%22%3Anull%2C%22cat3%22%3Anull%2C%22cat4%22%3Anull%2C%22theme%22%3Anull%2C%22engineer%22%3Anull%2C%22location%22%3Anull%2C%22division%22%3Anull%2C%22overdue%22%3Afalse%2C%22filters%22%3A%7B%22newCheckbox%22%3Atrue%2C%22appointedCheckbox%22%3Atrue%2C%22performedCheckbox%22%3Atrue%2C%22controlCheckbo"
		"x%22%3Atrue%7D%7D; DOMAIN=learning2.pflb.ru");

	web_url("learning2.pflb.ru:56902_2", 
		"URL=http://learning2.pflb.ru:56902/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://learning2.pflb.ru:56902/login", 
		"Snapshot=t73.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("checkLogin", 
		"URL=http://learning2.pflb.ru:56902/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t74.inf", 
		"Mode=HTML", 
		LAST);

	web_url("info", 
		"URL=http://learning2.pflb.ru:56902/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t75.inf", 
		"Mode=HTML", 
		LAST);

	web_url("4", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t76.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countByState", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t77.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("ticket", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/?state=-1,0,1,5&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t78.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	lr_end_transaction("UC1_TR1_LOGIN",LR_AUTO);

	lr_start_transaction("UC1_TR2_NEWINC");

	web_url("children", 
		"URL=http://learning2.pflb.ru:56902/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t79.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC1_TR2_NEWINC",LR_AUTO);

	lr_think_time(21);

	lr_start_transaction("UC1_TR3_LOCATION");
	
	web_reg_save_param_json(
        "ParamName=allshopids",
        "QueryString=$..id",
        "SelectAll=Yes", 
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");

	web_url("shops", 
		"URL=http://learning2.pflb.ru:56902/api/shops?q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t80.inf", 
		"Mode=HTML", 
		LAST);

	web_url("children_2", 
		"URL=http://learning2.pflb.ru:56902/api/user/catalog/node/0/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
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
		
	web_url("treeview", 
		"URL=http://learning2.pflb.ru:56902/api/user/catalog/treeview?shopid={shopid}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t82.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC1_TR3_LOCATION",LR_AUTO);

	maxI = atoi(lr_eval_string("{allservicesIDs_count}"));
	i = 1 + rand() % (maxI);
	
	sprintf(BuffPar, "{allservicesIDs_%i}", i);
	serviceID = lr_eval_string(BuffPar);
		
	sprintf(BuffPar, "{allservicesNames_%i}", i);
	serviceName = lr_eval_string(BuffPar);
	
	
	lr_param_sprintf("serviceID",serviceID);
	lr_param_sprintf("serviceName",serviceName);

	lr_start_transaction("UC1_TR4_QUESTION");

	web_url("children_3", 
		"URL=http://learning2.pflb.ru:56902/api/user/catalog/node/191/children/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t83.inf", 
		"Mode=HTML", 
		LAST);

	web_url("service", 
		"URL=http://learning2.pflb.ru:56902/api/user/catalog/node/191/service/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t84.inf", 
		"Mode=HTML", 
		LAST);

	web_url("191", 
		"URL=http://learning2.pflb.ru:56902/api/user/catalog/breadcrumbs/191", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t85.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_json(
        "ParamName=numberOfElements",
        "QueryString=$.numberOfElements",
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");
	            
	web_url("inventoryNumbers", 
		"URL=http://learning2.pflb.ru:56902/api/inventoryNumbers?serviceId={serviceID}&shopId={shopid}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t86.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC1_TR4_QUESTION",LR_AUTO);
	
	lr_think_time(10);

	lr_start_transaction("UC1_TR5_INVNUMBER");
	
	test = atoi(lr_eval_string("{numberOfElements}"));
	
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

	web_url("inventoryNumbers_2", 
		"URL=http://learning2.pflb.ru:56902/api/inventoryNumbers?shopId={shopid}&serviceId={serviceID}&serviceId={serviceID}&q=&page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t87.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC1_TR5_INVNUMBER",LR_AUTO);

	lr_start_transaction("UC1_TR6_ADDFILE");

	web_add_auto_header("Origin", 
		"http://learning2.pflb.ru:56902");

	lr_think_time(16);
	
	web_reg_save_param_json(
        "ParamName=fileID",
        "QueryString=$..id",
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");

	web_submit_data("file", 
		"Action=http://learning2.pflb.ru:56902/api/ticket/file/", 
		"Method=POST", 
		"EncType=multipart/form-data", 
		"TargetFrame=", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t88.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=files", "Value=dist_ru (2)(1).zip", "File=Yes", ENDITEM, 
		LAST);

	lr_end_transaction("UC1_TR6_ADDFILE",LR_AUTO);

	lr_think_time(22);

		

	lr_start_transaction("UC1_TR7_CREATE");

	web_custom_request("ticket_2", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t89.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
	//	"BodyBinary={\"text\":\"TESTDESCRIPTIONTEST\",\"header\":\"\\xD0\\xA1\\xD0\\xBB\\xD0\\xBE\\xD0\\xBC\\xD0\\xB0\\xD0\\xBD\\xD0\\xB0 \\xD0\\xBA\\xD0\\xBD\\xD0\\xBE\\xD0\\xBF\\xD0\\xBA\\xD0\\xB0 \\xD0\\xBB\\xD0\\xB8\\xD1\\x84\\xD1\\x82\\xD0\\xB0\",\"ticketStateId\":0,\"serviceId\":\"2912\",\"files\":[4395],\"inventoryNumberId\":\"7\",\"shopId\":\"4\"}", 
		"BodyBinary={\"text\":\"{testtext}\",\"header\":\"\{serviceName}\",\"ticketStateId\":0,\"serviceId\":\"{serviceID}\",\"files\":[{fileID}],\"inventoryNumberId\":\"{InventoryNumber}\",\"shopId\":\"{shopid}\"}", 		
		LAST);

	lr_end_transaction("UC1_TR7_CREATE",LR_AUTO);

	lr_start_transaction("UC1_TR8_OKBUTTON");

	web_revert_auto_header("Origin");

	web_revert_auto_header("X-Requested-With");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(12);

	web_url("learning2.pflb.ru:56902_3", 
		"URL=http://learning2.pflb.ru:56902/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t90.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("checkLogin_2", 
		"URL=http://learning2.pflb.ru:56902/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t91.inf", 
		"Mode=HTML", 
		LAST);

	web_url("info_2", 
		"URL=http://learning2.pflb.ru:56902/api/user/info", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t92.inf", 
		"Mode=HTML", 
		LAST);

	web_url("4_2", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/countByState/4", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t93.inf", 
		"Mode=HTML", 
		LAST);

	web_url("countByState_2", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t94.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC1_TR8_OKBUTTON",LR_AUTO);

	lr_think_time(8);

	lr_start_transaction("UC1_TR9_LOGOUT");

	web_url("logout", 
		"URL=http://learning2.pflb.ru:56902/api/logout", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t95.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("login_3", 
		"URL=http://learning2.pflb.ru:56902/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t96.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC1_TR9_LOGOUT",LR_AUTO);

	return 0;
}