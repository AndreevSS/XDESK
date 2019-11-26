Action()
{

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

	lr_start_transaction("UC4_TR1_LOGIN");

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

	lr_end_transaction("UC4_TR1_LOGIN",LR_AUTO);

	lr_start_transaction("UC4_TR2_SELECT_TASKS");

	web_url("countByState_2", 
		"URL=http://learning2.pflb.ru:56902/api/task/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_json(
        "ParamName=TaskIDs",
        "QueryString=$..parentId",
        "SelectAll=Yes", 
        SEARCH_FILTERS,
        "Scope=Body",
        "LAST");

	web_custom_request("task", 
		"URL=http://learning2.pflb.ru:56902/api/task/?state=1&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	lr_end_transaction("UC4_TR2_SELECT_TASKS",LR_AUTO);
	
	lr_param_sprintf("TaskID",lr_paramarr_random("TaskIDs"));

	lr_start_transaction("UC4_TR3_OPEN_TASK");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(11);

	web_url("task.dust", 
		"URL=http://learning2.pflb.ru:56902/engineer/task/task.dust", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t39.inf", 
		LAST);

	web_url("task.js", 
		"URL=http://learning2.pflb.ru:56902/engineer/task/task.js", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t40.inf", 
		LAST);

	web_url("149376", 
		"URL=http://learning2.pflb.ru:56902/api/task/{TaskID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		LAST);

	web_url("checkLogin_4", 
		"URL=http://learning2.pflb.ru:56902/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		LAST);

	web_url("comment_2", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/{TaskID}/comment/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC4_TR3_OPEN_TASK",LR_AUTO);

	lr_start_transaction("UC4_TR4_TO_TICKET");

	web_custom_request("149377_2", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/{TaskID}", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	web_url("comment_2", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/{TaskID}/comment/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC4_TR4_TO_TICKET",LR_AUTO);

	lr_start_transaction("UC4_TR5_TICKET_CLOSE");

	web_add_header("Origin", 
		"http://learning2.pflb.ru:56902");

	lr_think_time(38);

	web_custom_request("solve", 
		"URL=http://learning2.pflb.ru:56902/api/ticket/{TaskID}/solve/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://learning2.pflb.ru:56902/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	lr_end_transaction("UC4_TR5_TICKET_CLOSE",LR_AUTO);

	lr_start_transaction("UC4_TR6_LOGOUT");

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

	lr_end_transaction("UC4_TR6_LOGOUT",LR_AUTO);

	return 0;
}