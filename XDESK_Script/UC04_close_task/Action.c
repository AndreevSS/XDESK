Action()
{

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_url("Homepage", 
		"URL=http://{URL}:{port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t67.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/login", 
		"URL=http://{URL}:{port}/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t71.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("UC4_TR1_LOGIN");
	

	

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



	web_url("Homepage", 
		"URL=http://{URL}:{port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{URL}:{port}/login", 
		"Snapshot=t73.inf", 
		"Mode=HTML", 
		LAST);

	

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

	lr_end_transaction("UC4_TR1_LOGIN",LR_AUTO);

	lr_start_transaction("UC4_TR2_SELECT_TASKS");

	web_url("/api/task/countByState/", 
		"URL=http://{URL}:{port}/api/task/countByState/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
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

	web_custom_request("/api/task/?state=1&page=0&size=10", 
		"URL=http://{URL}:{port}/api/task/?state=1&page=0&size=10", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	lr_end_transaction("UC4_TR2_SELECT_TASKS",LR_AUTO);
	
	lr_param_sprintf("TaskID",lr_paramarr_random("TaskIDs"));

	lr_start_transaction("UC4_TR3_OPEN_TASK");

	

	

	web_url("/engineer/task/task.dust", 
		"URL=http://{URL}:{port}/engineer/task/task.dust", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t39.inf", 
		LAST);

	web_url("/engineer/task/task.js", 
		"URL=http://{URL}:{port}/engineer/task/task.js", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t40.inf", 
		LAST);

	web_url("/api/task/{TaskID}", 
		"URL=http://{URL}:{port}/api/task/{TaskID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t41.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/checkLogin", 
		"URL=http://{URL}:{port}/api/checkLogin", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t42.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/ticket/{TaskID}/comment/", 
		"URL=http://{URL}:{port}/api/ticket/{TaskID}/comment/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t43.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC4_TR3_OPEN_TASK",LR_AUTO);

	lr_start_transaction("UC4_TR4_TO_TICKET");

	web_custom_request("/api/ticket/{TaskID}", 
		"URL=http://{URL}:{port}/api/ticket/{TaskID}", 
		"Method=GET", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	web_url("/api/ticket/{TaskID}/comment/", 
		"URL=http://{URL}:{port}/api/ticket/{TaskID}/comment/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC4_TR4_TO_TICKET",LR_AUTO);

	lr_start_transaction("UC4_TR5_TICKET_CLOSE");

	

	

	web_custom_request("/api/ticket/{TaskID}/solve/", 
		"URL=http://{URL}:{port}/api/ticket/{TaskID}/solve/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	lr_end_transaction("UC4_TR5_TICKET_CLOSE",LR_AUTO);

	lr_start_transaction("UC4_TR6_LOGOUT");

	web_url("/api/logout", 
		"URL=http://{URL}:{port}/api/logout", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t95.inf", 
		"Mode=HTML", 
		LAST);

	
	

	web_url("/login", 
		"URL=http://{URL}:{port}/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t96.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC4_TR6_LOGOUT",LR_AUTO);

	return 0;
}