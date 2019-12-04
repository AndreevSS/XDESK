Login()
{
	
	lr_start_transaction("UC1_TR1_LOGIN");

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

	web_url("Homepage_2", 
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

	lr_end_transaction("UC1_TR1_LOGIN",LR_AUTO);
	
	return 0;
}
