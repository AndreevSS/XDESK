Comment_task()
{
	lr_start_transaction("UC3_TR2_SELECT_TASKS");

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

	lr_end_transaction("UC3_TR2_SELECT_TASKS",LR_AUTO);
	
	lr_param_sprintf("TaskID",lr_paramarr_random("TaskIDs"));

	lr_start_transaction("UC3_TR3_OPEN_TASK");

	

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

	lr_end_transaction("UC3_TR3_OPEN_TASK",LR_AUTO);

	lr_start_transaction("UC3_TR5_SUBMIT_COMMENT");
	
	BeforeRequest();

	web_custom_request("/api/ticket/{TaskID}/comment/", 
		"URL=http://{URL}:{port}/api/ticket/{TaskID}/comment/", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t45.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"text\":\"{TestCommentary}\",\"files\":[]}", 
		LAST);
	
	AfterRequest("comment/");
	
	web_url("/api/ticket/{TaskID}/comment/", 
		"URL=http://{URL}:{port}/api/ticket/{TaskID}/comment/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t46.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC3_TR5_SUBMIT_COMMENT",LR_AUTO);
	
	lr_think_time(thinktime1);
	
	return 0;
}
