int bytesbeforerequest;

int BeforeRequest()
{
	
	web_get_int_property(HTTP_INFO_TOTAL_RESPONSE_STAT);
	web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	web_get_int_property(HTTP_INFO_DOWNLOAD_TIME);
	
	bytesbeforerequest =  web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	return;
}

char * AfterRequest(char * label)
{
	char * measurement = "loadrunner";
//	char * label;
	int responseCode;
	int elapsedTime;
	int bytes;
	int sentbytes;
	char success [5];
	char * URL;
	char * timestamp;
	char result [256];

	//web_save_timestamp_param("TimeEnd", LAST);
	lr_save_timestamp("TimeEnd", "DIGITS=16",LAST);

	responseCode = web_get_int_property(HTTP_INFO_RETURN_CODE);

	sprintf(success, "%d", responseCode);
	if ((success[0] == '2') || (success[0] == '3'))
		{
			sprintf(success, "true");
		}
	else
		{
			sprintf(success, "false");
		};

		
	bytes = web_get_int_property(HTTP_INFO_DOWNLOAD_SIZE);
	sentbytes = web_get_int_property(HTTP_INFO_TOTAL_REQUEST_STAT);
	
	sentbytes = sentbytes - bytesbeforerequest;
	
	elapsedTime = web_get_int_property(HTTP_INFO_DOWNLOAD_TIME);
	timestamp = lr_eval_string("{TimeEnd}");
	sprintf(timestamp, "%s000",timestamp);
	URL = lr_eval_string("{URL}");
			
	sprintf(result, "%s,label=%s,responseCode=%d,success=%s responseTime=%d,bytes=%d,sentBytes=%d,URL=\"%s\" %s",
	        measurement, label, responseCode, success, elapsedTime, bytes, sentbytes, URL, timestamp);
		
	lr_save_string(result,"result");
		
	lr_message(result);

	web_custom_request("DB_Request",
	                   "Method=POST",
	                   "URL=http://localhost:8086/write?db=inflxdb", 
	                   "Body={result}",
	                   LAST);
	return;
}