Create_task()
{
	
	int randomID = 0;
	char buffer [128];
	
	char * serviceID;
	char * serviceName;
	
	srand(time(NULL));
	
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

	randomID = 1 + rand() % (atoi(lr_eval_string("{allservicesIDs_count}")));
	
	sprintf(buffer, "{allservicesIDs_%i}", randomID);
	serviceID = lr_eval_string(buffer);
		
	sprintf(buffer, "{allservicesNames_%i}", randomID);
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
	
	if (atoi(lr_eval_string("{numberOfElements}")) > 0)
		{
			lr_param_sprintf("InventoryNumber",lr_paramarr_random("allInventoryNumbers"));
		};

	lr_start_transaction("UC1_TR7_CREATE");
	
	BeforeRequest();	

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
					"\"files\":[],\"inventoryNumberId\":\"{InventoryNumber}\",\"shopId\":\"{shopid}\"}",
		LAST);
	
	AfterRequest("/api/ticket");

	lr_end_transaction("UC1_TR7_CREATE",LR_AUTO);

	lr_start_transaction("UC1_TR8_OKBUTTON");

	web_url("{URL}:{port}_3", 
		"URL=http://{URL}:{port}/", 
		"TargetFrame=", 
		"Resource=0", 
		"Referer=http://{URL}:{port}/", 
		"Snapshot=t90.inf", 
		"Mode=HTML", 
		LAST);

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
	
	lr_think_time(thinktime1);
	
	return 0;
}
