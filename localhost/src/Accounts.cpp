// The new version (localhost/ref/accountHandling.cpp --> localhost/src/Accounts.cpp)
#include "Accounts.h"

/* Get the percentage of the linked account from the brewscore at the given index */
std::string Accounts::getpercentfrombrewscore(std::string brewScore, int index) {
	cJSON *jsonBrewScoreRaw, *jsonBrewScore, *jsonArrayItem, *jsonAccountPercent;

	jsonBrewScoreRaw = cJSON_Parse(brewScore);
	jsonBrewScore = cJSON_GetObjectItem(jsonBrewScoreRaw, BREWSCORE);
	jsonArrayItem = cJSON_GetArrayItem(jsonBrewScore, index);
	jsonAccountPercent = cJSON_GetObjectItem(jsonArrayItem, ACCOUNTPERCENT);

	char accountPercent[NIBBLE_LEN] = {'\0'};
	snprintf(accountPercent, NIBBLE_LEN, "%s", cJSON_Print(jsonAccountPercent));
	char *accountPercentRet = MEM_MALLOC(NIBBLE_LEN);
	strncpy(accountPercentRet, accountPercent, NIBBLE_LEN);

	free(jsonBrewScoreRaw);
	free(jsonBrewScore);
	free(jsonArrayItem);
	free(jsonAccountPercent);
	return accountPercentRet;
}

/* Get the name of the linked account from the brewscore at the given index */
std::string Accounts::getnamefrombrewscore(std::string brewScore, int index) {
	cJSON *jsonBrewScoreRaw, *jsonBrewScore, *jsonArrayItem, *jsonAccountName;

	jsonBrewScoreRaw = cJSON_Parse(brewScore);
	jsonBrewScore = cJSON_GetObjectItem(jsonBrewScoreRaw, BREWSCORE);
	jsonArrayItem = cJSON_GetArrayItem(jsonBrewScore, index);
	jsonAccountName = cJSON_GetObjectItem(jsonArrayItem, ACCOUNTNAME);

	char accountName[SHORT_LEN] = {'\0'};
	snprintf(accountName, SHORT_LEN, "%s", cJSON_Print(jsonAccountName));
	char *accountNameRet = MEM_MALLOC(SHORT_LEN);
	strncpy(accountNameRet, accountName, SHORT_LEN);

	free(jsonBrewScoreRaw);
	free(jsonBrewScore);
	free(jsonArrayItem);
	free(jsonAccountName);
	return accountNameRet;
}

/* Get the name of the account from linked accounts at the given index */
std::string Accounts::getnamefromlinkedaccounts(std::string linkedAccountsJSON, int index) {
	cJSON *jsonLinkedAccountsRaw, *jsonLinkedAccounts, *jsonArrayItem, *jsonAccountName;

	jsonLinkedAccountsRaw = cJSON_Parse(linkedAccountsJSON);
	jsonLinkedAccounts = cJSON_GetObjectItem(jsonLinkedAccountsRaw, ACCOUNTS);
	jsonArrayItem = cJSON_GetArrayItem(jsonLinkedAccounts, index);
	jsonAccountName = cJSON_GetObjectItem(jsonArrayItem, ACCOUNTNAME);

	char accountName[SHORT_LEN] = {'\0'};
	snprintf(accountName, SHORT_LEN, "%s", cJSON_Print(jsonAccountName));
	char *accountNameRet = MEM_MALLOC(SHORT_LEN);
	strncpy(accountNameRet, accountName, SHORT_LEN);

	free(jsonLinkedAccountsRaw);
	free(jsonLinkedAccounts);
	free(jsonArrayItem);
	free(jsonAccountName);
	return accountNameRet;
}

/* Get the total space of the account from linked accounts at the given index */
double Accounts::gettotalspacefromlinkedaccounts(std::string linkedAccountsJSON, int index) {
	cJSON *jsonLinkedAccountsRaw, *jsonLinkedAccounts, *jsonArrayItem, *jsonTotalSpace;

	jsonLinkedAccountsRaw = cJSON_Parse(linkedAccountsJSON);
	jsonLinkedAccounts = cJSON_GetObjectItem(jsonLinkedAccountsRaw, ACCOUNTS);
	jsonArrayItem = cJSON_GetArrayItem(jsonLinkedAccounts, index);
	jsonTotalSpace = cJSON_GetObjectItem(jsonArrayItem, TOTALSPACE);

	char totalSpace[SHORT_LEN] = {'\0'};
	snprintf(totalSpace, SHORT_LEN, "%s", cJSON_Print(jsonTotalSpace));
	double perAccountTotalSpace = atof(totalSpace);

	free(jsonLinkedAccountsRaw);
	free(jsonLinkedAccounts);
	free(jsonArrayItem);
	free(jsonTotalSpace);
	return perAccountTotalSpace;
}

/* Get the used space of the account from linked accounts at the given index */
double Accounts::getusedspacefromlinkedaccounts(std::string linkedAccountsJSON, int index) {
	cJSON *jsonLinkedAccountsRaw, *jsonLinkedAccounts, *jsonArrayItem, *jsonFreeSpace;

	jsonLinkedAccountsRaw = cJSON_Parse(linkedAccountsJSON);
	jsonLinkedAccounts = cJSON_GetObjectItem(jsonLinkedAccountsRaw, ACCOUNTS);
	jsonArrayItem = cJSON_GetArrayItem(jsonLinkedAccounts, index);
	jsonFreeSpace = cJSON_GetObjectItem(jsonArrayItem, USEDSPACE);

	char freeSpace[SHORT_LEN] = {'\0'};
	snprintf(freeSpace, SHORT_LEN, "%s", cJSON_Print(jsonFreeSpace));
	double perAccountFreeSpace = atof(freeSpace);

	free(jsonLinkedAccountsRaw);
	free(jsonLinkedAccounts);
	free(jsonArrayItem);
	free(jsonFreeSpace);
	return perAccountFreeSpace;
}

/* Get the max file size of the account from linked accounts at the given index */
double Accounts::getmaxfilesizefromlinkedaccounts(std::string linkedAccountsJSON, int index) {
	cJSON *jsonLinkedAccountsRaw, *jsonLinkedAccounts, *jsonArrayItem, *jsonMaxFileSize;

	jsonLinkedAccountsRaw = cJSON_Parse(linkedAccountsJSON);
	jsonLinkedAccounts = cJSON_GetObjectItem(jsonLinkedAccountsRaw, ACCOUNTS);
	jsonArrayItem = cJSON_GetArrayItem(jsonLinkedAccounts, index);
	jsonMaxFileSize = cJSON_GetObjectItem(jsonArrayItem, MAXFILESIZE);

	char maxFileSize[SHORT_LEN] = {'\0'};
	snprintf(maxFileSize, SHORT_LEN, "%s", cJSON_Print(jsonMaxFileSize));
	double perAccountMaxFileSize = atof(maxFileSize);

	free(jsonLinkedAccountsRaw);
	free(jsonLinkedAccounts);
	free(jsonArrayItem);
	free(jsonMaxFileSize);
	return perAccountMaxFileSize;
}
