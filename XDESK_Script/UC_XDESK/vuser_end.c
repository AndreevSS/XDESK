vuser_end()
{
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
	
	lr_think_time(thinktime1);
	return 0;
}
