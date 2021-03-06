# Define the targets to be created - cbUpload and cbDownload
{
	"targets": [
	{
		'target_name': 'cbUpload',
		'defines': [ 'V8_DEPRECATION_WARNINGS=1' ],
		'sources': [ 'cbUpload.cpp', 'mainCBUpload.cpp' ],
		'include_dirs': [ '../include' ],
		'libraries': [ '-lcJSON', '-lCloudBrew' ],
		'cflags': ['-Wall', '-std=c++11']
	},
	{
		'target_name': 'cbDownload',
		'defines': [ 'V8_DEPRECATION_WARNINGS=1' ],
		'sources': [ 'cbDownload.cpp', 'mainCBDownload.cpp' ],
		'include_dirs': [ '../include' ],
		'libraries': [ '-lcJSON', '-lCloudBrew' ],
		'cflags': ['-Wall', '-std=c++11']
	},
	]
}
