/**
{file:
	{name: VidyoClientPrivate.h}
	{description: VidyoClient Library.}
    {copyright:
		(c) 2006-2009 Vidyo, Inc.,
		433 Hackensack Avenue, 6th Floor,
		Hackensack, NJ  07601.
		All rights reserved.
		The information contained herein is proprietary to Vidyo, Inc.
		and shall not be reproduced, copied (in whole or in part), adapted,
		modified, disseminated, transmitted, transcribed, stored in a retrieval
		system, or translated into any language in any form by any means
		without the express written consent of Vidyo, Inc.}
}
*/

#ifndef VIDYO_CLIENT_PRIVATE_H
#define VIDYO_CLIENT_PRIVATE_H

#ifdef BUILD_VIDYO_DESKTOP_QMAKE
/* Following #include needed to define wchar_t when building using qmake-generated project file */
#include <stdlib.h>
#endif // BUILD_VIDYO_DESKTOP_QMAKE
#include <stdio.h>
#include <limits.h>
#include "VidyoTypes.h"
#include "VidyoClientConstants.h"
#include "VidyoClientParameters.h"

/* Constants */
#define VIDYO_CLIENT_PRIVATE_EVENT_BASE 200000
#define VIDYO_CLIENT_PRIVATE_REQUEST_BASE 300000
#define useVCSOAPfor_Autoupgrade VIDYO_TRUE
#define MAX_ALARM_LEN (100+1)
#define MAX_LOG_LEN (2047+1)

/* Start of constant definitions used in SOAP interface */

/* normalized to public constants */
#define VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_URI_SIZE			URI_LEN 
#define VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE				VIDYO_CLIENT_USERNAME_SIZE
#define VIDYO_CLIENT_PRIVATE_SOAP_PASSWORD_SIZE				PASSWORD_SIZE

#define VIDYO_CLIENT_PRIVATE_SOAP_FIELD_SIZE 257

#define VIDYO_CLIENT_PRIVATE_SOAP_INSTALLER_URI_SIZE MAX_INSTALLER_URI_SIZE
#define VIDYO_CLIENT_PRIVATE_SOAP_INSTALLER_PATH_SIZE 512
//#define VIDYO_CLIENT_PRIVATE_SOAP_PASSWORD_SIZE 64
#define VIDYO_CLIENT_PRIVATE_SOAP_IPADDRESS_SIZE MAX_IPADDRESS_LEN
#define VIDYO_CLIENT_PRIVATE_SOAP_STATUS_SIZE 9

//#define VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_URI_SIZE VIDYO_CLIENT_PRIVATE_SOAP_FIELD_SIZE
#define VIDYO_CLIENT_PRIVATE_SOAP_CURRENT_TAG_SIZE VIDYO_CLIENT_VERSION_SIZE

//#define VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE 128

#define VIDYO_CLIENT_PRIVATE_SOAP_PAK_SIZE VIDYO_CLIENT_PRIVATE_SOAP_FIELD_SIZE
#define VIDYO_CLIENT_PRIVATE_SOAP_BAK_SIZE VIDYO_CLIENT_PRIVATE_SOAP_FIELD_SIZE
#define VIDYO_CLIENT_PRIVATE_SOAP_LAK_SIZE VIDYO_CLIENT_PRIVATE_SOAP_FIELD_SIZE

#define VIDYO_CLIENT_PRIVATE_SOAP_HOSTNAME_SIZE VIDYO_CLIENT_PRIVATE_SOAP_FIELD_SIZE

#define VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE MAX_EID_SIZE
#define VIDYO_CLIENT_PRIVATE_SOAP_LONG_EID_SIZE 256
#define VIDYO_CLIENT_PRIVATE_SOAP_ROOMPIN_SIZE 5 //portal max is 4
#define VIDYO_CLIENT_PRIVATE_SOAP_ROOMEXTN_SIZE 17 // portal max is 16
#define VIDYO_CLIENT_PRIVATE_SOAP_INVITECONTENT_SIZE 1500
#define VIDYO_CLIENT_PRIVATE_SOAP_PORTALFEATURE_NUM VIDYO_CLIENT_PORTAL_FEATURE_NAME_MAX
#define VIDYO_CLIENT_PRIVATE_SOAP_ACCESSOPTIONS_NUM 4
#define VIDYO_CLIENT_PRIVATE_SOAP_ACCESSOPTIONS_SIZE USERID_SIZE

#define VIDYO_CLIENT_PRIVATE_SOAP_TENANT_SIZE VIDYO_CLIENT_PRIVATE_SOAP_FIELD_SIZE
#define VIDYO_CLIENT_PRIVATE_SOAP_PARTICIPANTID_SIZE MAX_EID_SIZE

#define VIDYO_CLIENT_PRIVATE_SOAP_SEARCH_SIZE		VIDYO_CLIENT_PORTAL_SEARCH_SIZE
#define VIDYO_CLIENT_PRIVATE_SOAP_PIN_SIZE						PIN_SIZE // DB max is 64 and portal max is 16
#define VIDYO_CLIENT_PRIVATE_SOAP_EXTENSION_SIZE	VIDYO_MAX_EXTENSION_SIZE // DB max is 64 and portal max is 16
#define VIDYO_CLIENT_PRIVATE_SOAP_VIDYO_MANAGER_ID_SIZE VIDYO_MANAGER_ID_SIZE
#define VIDYO_CLIENT_PRIVATE_SOAP_ENDPOINT_LOCATION_TAG_SIZE ENDPOINT_LOCATION_TAG_SIZE
#define VIDYO_CLIENT_PRIVATE_SOAP_EMAIL_ADDRESS_SIZE VIDYO_MAX_EMAIL_ADDRESS_SIZE
#define VIDYO_CLIENT_PRIVATE_SOAP_PORTALVERSION_SIZE SIGNIN_PORTALVERSION_SIZE
#define VIDYO_CLIENT_PRIVATE_SOAP_LANGUAGE_CODE_SIZE 6
#define VIDYO_CLIENT_PRIVATE_SOAP_TENANT_ADDRESS_SIZE 128
#define VIDYO_CLIENT_PRIVATE_SOAP_ROOMKEY_SIZE 					ROOMKEY_SIZE
#define VIDYO_CLIENT_PRIVATE_SOAP_BANNER_COLUMN_SIZE 64
#define VIDYO_CLIENT_PRIVATE_SOAP_BANNER_SIZE 2048
#define VIDYO_CLIENT_PRIVATE_SOAP_LOGIN_HISTORY_SIZE 5
#define VIDYO_CLIENT_PRIVATE_RECORDER_NAME_SIZE USERID_SIZE 
#define VIDYO_CLIENT_PRIVATE_SOAP_ROOMDIALIN_SIZE 15

#define VIDYO_CLIENT_PRIVATE_SOAP_RECORDING_PROFILE_SIZE				16
#define VIDYO_CLIENT_PRIVATE_SOAP_RECORDING_PROFILE_DESCRIPTION_SIZE	64
#define VIDYO_CLIENT_PRIVATE_SOAP_RECORDING_PROFILE_PREFIX_SIZE			64
#define VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_PREFIX_SIZE MAX_PORTAL_PREFIX_SIZE

#define VIDYO_CLIENT_PLATFORM_OS_NAME_LEN 24
#define VIDYO_CLIENT_DEVICE_MODEL_LEN 24
/* End of constant definitions used in SOAP interface */

/* Start of constant definitions used in Portal Data Cache interface */

#define VIDYO_CLIENT_PRIVATE_EVENT_PORTAL_DATA_CACHE_SIZE 50

/* End of constant definitions used in Portal Data Cache interface */

// Private events from GUI to Vidyo Client Library
typedef enum VidyoClientPrivateInEvent_
{
	VIDYO_CLIENT_PRIVATE_IN_EVENT_MIN = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 100,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_LAYOUT = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 100,			// takes VidyoClientPrivateInEventLayout param
	VIDYO_CLIENT_PRIVATE_IN_EVENT_START_MY_MEETING = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 200,	// takes VidyoClientPrivateSoapInEventStartMyConference param
	VIDYO_CLIENT_PRIVATE_IN_EVENT_SHOW_LOG_SETTINGS = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 300,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_CHANGE_BANDWIDTHS = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 400,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_SET_MONITORS = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 500,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_SET_BACKGROUND = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 600,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_GET_CONFIGURATION = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 700,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_SET_CONFIGURATION = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 701,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_JOIN_SVCS = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 800,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_RENDERER_SHOW_ICON = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 901,//shows icon Recording in iOS
	VIDYO_CLIENT_PRIVATE_IN_EVENT_VCSOAP = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1000,			// takes RequestClientVersion etc as param
	VIDYO_CLIENT_PRIVATE_IN_EVENT_PORTAL_DATA_CACHE = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1100,// all IN events related to caching portal data and operations on cache
	VIDYO_CLIENT_PRIVATE_IN_EVENT_STOP_EMCP = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1111,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_RESTART_EMCP_USER = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1112,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_RESTART_EMCP = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1113,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_SET_PARTICIPANT_LIMIT = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1114, // VidyoClientPrivateInEventParticipantLimit
	VIDYO_CLIENT_PRIVATE_IN_EVENT_RENDERER_SHOW_PARTICIPANT_NAME = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1115,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_RENDERER_SHOW_VIDEO_STATISTIC = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1116,

	/* Start of messages for Android Client only */
	VIDYO_CLIENT_PRIVATE_IN_EVENT_ANDROID_TOUCH_START_EVENT	= VIDYO_CLIENT_PRIVATE_EVENT_BASE	+ 1200,	// touch start event, uses VidyoClientOutEventMouse to pass event info
	VIDYO_CLIENT_PRIVATE_IN_EVENT_ANDROID_TOUCH_STOP_EVENT	= VIDYO_CLIENT_PRIVATE_EVENT_BASE	+ 1201,	// touch stop event, uses VidyoClientOutEventMouse to pass event info
	VIDYO_CLIENT_PRIVATE_IN_EVENT_ANDROID_TOUCH_MOVE_EVENT	= VIDYO_CLIENT_PRIVATE_EVENT_BASE	+ 1202,	// touch move event, uses VidyoClientOutEventMouse to pass event info
	/* end of messages for Android Client only */

	VIDYO_CLIENT_PRIVATE_IN_EVENT_LOW_MEMORY = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1300, // memory low warning (iOS)
    
	VIDYO_CLIENT_PRIVATE_IN_EVENT_SELECT_CAMERA = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1500,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_SELECT_SPEAKER = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1501,

	/* Start of messages used by VidyoWeb ONLY */
	VIDYO_CLIENT_PRIVATE_IN_EVENT_GET_WINDOWS_EXT = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1600,
	/* end of messages used by VidyoWeb ONLY */

	/* Start of messages for VidyoRoom only */
	VIDYO_CLIENT_PRIVATE_IN_EVENT_PREVIEW = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 50000,
	VIDYO_CLIENT_PRIVATE_IN_EVENT_VGA2USB = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 50001,
	/* End of messages for VidyoRoom only */

	VIDYO_CLIENT_PRIVATE_IN_EVENT_MAX = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 99999,
} VidyoClientPrivateInEvent;

// Private events from Vidyo Client Library to GUI (used to be known as actions)
typedef enum VidyoClientPrivateOutEvent_
{
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_MIN = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 100,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_SHARED_APP_ADD = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 200,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_SHARED_APP_REM = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 201,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_ALARMS_RAISED = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 300,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_ALARMS_CLEARED = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 301,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_PARTICIPANTS_LIMIT_BANDW = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 400,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_PARTICIPANTS_LIMIT_SAFE = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 401,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_PARTICIPANTS_CHANGED = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 600, // Use VIDYO_CLIENT_OUT_EVENT_PARTICIPANTS_CHANGED instead of this
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_ALLOW_UPGRADE = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 700,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_GET_CONFIGURATION_RESPONSE = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 800,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_VCSOAP = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 900,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_PORTAL_DATA_CACHE = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1000,// all OUT events related to caching portal data and operations on cache
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_PLAY_SOUND_DONE = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1100, //inform the user that a sound buffer finished playing , using VidyoClientInEventPlaySound structure
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_WEBPROXY_UPDATE_NEEDED = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1200,	// Inform listener (Android app. for example) to run the Web Proxy PAC script
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_GUEST_CONFERENCE_ENDED = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1300,	// Inform listener that a guest conference has just ended
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_RESET_EMCP_AFTER_GUEST_FAILED = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1400,	// Inform listener that a reset emcp after guest conference has just failed. client is now in a logout state.
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_LOG = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1600,  // logs sent to application
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_GUEST_CONFERENCE_BEGIN_PROMPT = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1700,  // guest link notification
    VIDYO_CLIENT_PRIVATE_OUT_EVENT_CONFERENCE_CLEARED = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 1810,
	/*!
		Report the status of communication with Portal. This out event is used
		report the portal communication status for searching contact, add or remove contacts,
		control meeting etc.
	
		@see Corresponding parameter structure #VidyoClientPrivateOutEventPortalCommunicationStatus
	*/
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_PORTAL_COMMUNICATION_STATUS = VIDYO_CLIENT_PRIVATE_EVENT_BASE+1900,
	/*!
		Report the changes in signin flow. Example of changes are retry to secure portal,
		redirecting to secure portal.

		@see Corresponding parameter structure #VidyoClientPrivateOutEventSignInUpdate
	*/
    VIDYO_CLIENT_PRIVATE_OUT_EVENT_SIGNIN_UPDATE = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 2000,
	/*!
		Report that user login using external (e.g. browser) or Report that automatic login 
		using previously provided credntial is started.

		@see Corresponding parameter structure #VidyoClientPrivateOutEventLoginStarted
	*/
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_LOGIN_STARTED = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 2001,
	/*!
		Report that credential required to login are not present or client is working again older
		portal and manual sign-in required.

		@see Corresponding parameter structure #VidyoClientPrivateOutEventNoLoginCredential
	*/
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_NO_LOGIN_CREDENTIAL = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 2002,
	/*!
		Report the status change Kiosk device.

		@see Corresponding parameter structure #VidyoClientPrivateOutEventKioskDeviceStateChanged
	*/
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_KIOSK_DEVICE_STATE_CHANGED = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 2100,
	/*!
		Report the low master volume indication for a audio device.

		@see Corresponding parameter structure #VidyoClientPrivateOutEventLowMasterVolume
	*/
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_LOW_MASTER_VOLUME = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 2110,

	/* Start of messages for VidyoRoom only */
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_VISCA = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 50000,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_SWB = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 50001,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_USB_CAPTURE = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 50002,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_CHANGE_FOCUS = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 50003,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_NETWORK_CONTROL = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 50004,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_CHANGE_CAMERA_MODE = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 50005,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_FRAMEWORK_DONE = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 50006,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_ADJUST_MONITORS = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 50007,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_SET_VISCA = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 50008,
	/* End of messages for VidyoRoom only */
    
    /* Start of messages used by Android (currently) */
    /*!
        Report that a Remote source is added or removed.  Android needs to know when remote
        sources are added and removed so that if the menu bar is visible it can be updated
        appropriately.
     */
    VIDYO_CLIENT_PRIVATE_OUT_EVENT_REMOTE_SOURCE_ADD = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 60000,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_REMOTE_SOURCE_REM = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 60001,
    /* End of messages used by Android (currently) */
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_RENDERER_DOCS_CHANGED = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 60002,

	/* Start of messages used by VidyoWeb ONLY */
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_PLUGIN_CONNECTION_SUCCESS = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 70000,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_PLUGIN_CONNECTION_FAILURE = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 70001,
	VIDYO_CLIENT_PRIVATE_OUT_EVENT_GET_WINDOWS_EXT  = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 70002,
	/* End of messages used by VidyoWeb */

	VIDYO_CLIENT_PRIVATE_OUT_EVENT_MAX = VIDYO_CLIENT_PRIVATE_EVENT_BASE + 99999,
} VidyoClientPrivateOutEvent;

// Private requests from GUI to Vidyo Client Library
typedef enum VidyoClientPrivateRequest_
{
	VIDYO_CLIENT_PRIVATE_REQUEST_MIN = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 100,
	VIDYO_CLIENT_PRIVATE_REQUEST_SET_GUI_WINDOW = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 100,
	VIDYO_CLIENT_PRIVATE_REQUEST_SET_LAYOUT_RECT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 101,
	VIDYO_CLIENT_PRIVATE_REQUEST_SNAP_WINDOW_RESIZE = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 102,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_BW_STATUS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 200,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_BANDWIDTH_INFO = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 201,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_VIDEO_CAPTURE_RESOLUTION = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 202,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_VIDEO_CAPTURE_FRAME_RATE = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 203,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_VIDEO_ENCODE_RESOLUTION = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 204,	// takes VidyoRect param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_VIDEO_ENCODE_FRAME_RATE = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 205,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_VIDEO_FRAME_RATE_INFO = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 206,	// takes VidyoClientPrivateRequestGetVideoFrameRateInfo param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_NUM_IFRAMES = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 207,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_NUM_FIRS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 208,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_NUM_NACKS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 209,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_MEDIA_RTT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 210,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_RATE_SHAPER_INFO = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 211,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_CURRENT_CPU_UTIL = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 212,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_CURRENT_USER = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 300,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_LAYOUT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 400,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_SEND_MAX_KBPS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 500,
	VIDYO_CLIENT_PRIVATE_REQUEST_SET_SEND_MAX_KBPS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 501,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_RECV_MAX_KBPS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 502,
	VIDYO_CLIENT_PRIVATE_REQUEST_SET_RECV_MAX_KBPS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 503,
	VIDYO_CLIENT_PRIVATE_REQUEST_STATISTICS_ENABLE = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 700,			// takes NULL param
	VIDYO_CLIENT_PRIVATE_REQUEST_STATISTICS_DISABLE = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 701,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_TOTAL_VIDEO_RESOLUTION = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 702,	// takes float param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_NUM_PARTICIPANTS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 703,		// takes size_t param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_URI_AT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 704,		// takes char[30] param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_NAME_AT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 705,		// takes char[24] param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_NUM_FIRS_AT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 706,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_NUM_NACKS_AT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 707,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_VIDEO_FRAME_RATE_AT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 708,			// takes unsigned int param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_VIDEO_DECODED_FRAME_RATE_AT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 709,	// takes unsigned int param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_VIDEO_DISPLAYED_FRAME_RATE_AT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 710,// takes unsigned int param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_VIDEO_RESOLUTION_AT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 711,			// takes unsigned int param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_VIDEO_KBITS_PER_SEC_RECV_AT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 712,	// takes unsigned int param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_AUDIO_KBITS_PER_SEC_RECV_AT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 713,	// takes unsigned int param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_STATISTIC_AT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 714,// takes whole statistic structure
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_VIDEO_ENCODER_LAYERS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 715, // Takes VidyoClientPrivateRequestGetVideoEncoderLayers as param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_AUDIO_STATS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 716, // Takes VidyoClientPrivateRequestGetAudioStats as param
    VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_DETAILS_AT = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 717,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_INVITING_USER = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 800,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_OR_SET_WINDOW_SHARES = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 900,	// takes VidyoClientPrivateRequestGetOrSetWindowShares param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_NUM_DOCKED_WINDOWS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 1000,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_MEDIA_SERVER_IP = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 1100,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_ON_CALL_FLAG = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 1200,			// onCallFlag
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_USING_PROXY = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 1300,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_CURRENT_LANGUAGE = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 1400,
	VIDYO_CLIENT_PRIVATE_REQUEST_SET_CURRENT_LANGUAGE = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 1401,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PORTAL_SERVER_ADDRESS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 1600,	// takes char* param
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_WEB_PROXY_STATE = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 1700,		// takes char[MAX_URI_LEN] param
	VIDYO_CLIENT_PRIVATE_REQUEST_SHOW_AUDIO_DEBUG_WINDOW = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 1800,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_SIGNED_INFO = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 1900,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_AUDIO_ENERGY_INFO = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2000,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PORTAL_DATA_CACHE = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2100,		// takes VidyoClientPrivateRetrievePortalDataCache - Direct access to read all data from Portal Data Cache
	VIDYO_CLIENT_PRIVATE_REQUEST_SET_PORTAL_DATA_CACHE_DEBUG = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2101,// enable or disable Portal Data Cache debug
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PORTAL_DATA_CACHE_SUMMARY = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2102,// takes VidyoClientPrivateRetrievePortalDataCacheSummary  - Direct access to read summary of Portal Data Cache
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_ENTITY_INFO = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2105,				// get my entity info //TODO: this can be public in future
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_SELF_ACCOUNT_DATA = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2150,		// takes VidyoClientPrivateRequestSelfAccountData as input
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_RC_ENABLED = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2200,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_PLUGINS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2204,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_VIDYO_CLIENT_VERSION = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2205,
	VIDYO_CLIENT_PRIVATE_REQUEST_SET_PID = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2300,
	VIDYO_CLIENT_PRIVATE_REQUEST_SET_ENABLE_CLIENT_LINK = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2400,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_LECTURE_MODE_STATUS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2450,
 	/*!
		Used to control (enable or disable) the CPU and Bandwidth resource monitoring and taking actions based on that.
	
		@see Corresponding parameter structure #VidyoClientPrivateControlResourceMonitoring
	*/	
	VIDYO_CLIENT_PRIVATE_REQUEST_CONTROL_RESOURCE_MONITORING = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2455,
 	/*!
		Get the current AEC and AGC status being used.
	
		@see Corresponding parameter structure #VidyoClientPrivateRequestAecAgcInformation
	*/	
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_AEC_AGC_INFORMATION = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2510, 
	/*!
		Get the current devices (name, state and current selection).

		@see Corresponding parameter structure #VidyoClientPrivateRequestGetDevices
	*/
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_DEVICES = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2520,
	/*!
		Set the current devices selection change.

		@see Corresponding parameter structure #VidyoClientPrivateRequestSetDevices
	*/
	VIDYO_CLIENT_PRIVATE_REQUEST_SET_DEVICES = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2521,
	/*!
     Set the call windows to be auto cleaned
     
     @see Corresponding parameter structure #VidyoClientPrivateRequestSetCallWindowAutoClean
     */
	VIDYO_CLIENT_PRIVATE_REQUEST_SET_CALL_WINDOW_AUTO_CLEAN = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 2524,
	/* 	mouse events messages
		these mouse events are for environment like VidyoWeb on the mac
		Where mouse events can only be accepted from the GUI level and passed down instead of 
		the SDK generating them and sending them up
	*/
    VIDYO_CLIENT_PRIVATE_REQUEST_MOUSE_DOWN 							= VIDYO_CLIENT_PRIVATE_REQUEST_BASE       + 2700,
    VIDYO_CLIENT_PRIVATE_REQUEST_MOUSE_UP 								= VIDYO_CLIENT_PRIVATE_REQUEST_MOUSE_DOWN + 1,
    VIDYO_CLIENT_PRIVATE_REQUEST_MOUSE_MOVE 							= VIDYO_CLIENT_PRIVATE_REQUEST_MOUSE_DOWN + 2,
	VIDYO_CLIENT_PRIVATE_REQUEST_MOUSE_SCROLL							= VIDYO_CLIENT_PRIVATE_REQUEST_MOUSE_DOWN + 3,

	/* Start of messages for Android Client only */
	VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_BASE							= VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 4000,	
	VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_DO_RENDER						= VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_BASE + 1,				// force an imidiate rendering of screen
	VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_DO_SCENE_RESET					= VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_BASE + 2,				// force an imidiate reset of rendered scene
	VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_DO_GET_ENTITY_INFO				= VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_BASE + 6,				// get my entity info //TODO: might be replaced by otehr messages
	VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_SET_HAS_CAMERA					= VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_BASE	+ 7, 				// TEMPORARY: set to identify has front camera or not
    VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_TOUCH_START_EVENT              = VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_BASE + 8,                // ANDROID touch events
    VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_TOUCH_STOP_EVENT               = VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_BASE + 9,                // ANDROID touch events
    VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_TOUCH_MOVE_EVENT               = VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_BASE + 10,               // ANDROID touch events

    VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_SET_WEB_PROXY_DYNAMIC_VALUES	= VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_BASE + 11,		// Set the Web Proxy settings that get calculated in Java layer

    VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_DISABLE_SHARE_EVENTS           = VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_BASE + 12,		// Disable the output of Share Events, lets Renderer handle Application shares
    VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_ENABLE_SHARE_EVENTS            = VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_BASE + 13,		// Enable the output of Share Events, GUI/Client handles applicaiton share windows

	VIDYO_CLIENT_PRIVATE_REQUEST_SET_PIXEL_DENSITY						= VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_BASE + 14,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_VIDEO_CAPTURE_CAPABILITIES         = VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_BASE + 15,                // Get the possible camera capabilities (dimensions, fps)
	
	/* End of messages for Android Client only */

	/* Start of messages for Mobile Clients only */
	VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_BASE						= VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 5000,

	VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_CYCLE_RENDERER_STATS		= VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_BASE + 1,			// cycle Labels -> stats -> nothing (could be used by iOS as well)
	VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_CALL_ON_HOLD				= VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_BASE + 2,
	VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_GET_DEVICES_FROM_MANAGER 	= VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_BASE + 3,
	VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_SET_STATS_VISIBILITY		= VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_BASE + 4,
	VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_GET_STATS_VISIBILITY		= VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_BASE + 5,
	VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_SET_LABELS_VISIBILITY		= VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_BASE + 6,
	VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_GET_LABELS_VISIBILITY		= VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_BASE + 7,

	/* End of messages for Mobile Client only */
    

	/* Start of messages for VidyoRoom only */
	VIDYO_CLIENT_PRIVATE_REQUEST_SET_REMOTE_SHARE_ENABLED = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 50000,
	VIDYO_CLIENT_PRIVATE_REQUEST_GET_CAMERA_STATUS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 50001,
	VIDYO_CLIENT_PRIVATE_REQUEST_SEND_KEYPRESS = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 50002,	// takes unsigned int param

	/* End of messages for VidyoRoom only */
#ifdef VIDYO_INTERNAL_AUDIO_RECORDING_STATUS
	VIDYO_CLIENT_PRIVATE_REQUEST_LIMITED_AUDIO_CAPTURE,//audio recording request
	VIDYO_CLIENT_PRIVATE_REQUEST_START_STOP_AUDIO_CAPTURE,
	VIDYO_CLIENT_PRIVATE_REQUEST_RXIN_AUDIO_CAPTURE,
	VIDYO_CLIENT_PRIVATE_REQUEST_RXOUT_AUDIO_CAPTURE,
	VIDYO_CLIENT_PRIVATE_REQUEST_TXIN_AUDIO_CAPTURE,
	VIDYO_CLIENT_PRIVATE_REQUEST_TXOUT_AUDIO_CAPTURE,
	VIDYO_CLIENT_PRIVATE_REQUEST_RXIN_RXOUT_POSITIONS,
	VIDYO_CLIENT_PRIVATE_REQUEST_TXIN_TXOUT_POSITIONS,//END AUDIO RECORDING CODES
	VIDYO_CLIENT_PRIVATE_REQUEST_TX_AES_TUNING_APPLY,// Audio DSP tuning
#endif 

	VIDYO_CLIENT_PRIVATE_REQUEST_MAX = VIDYO_CLIENT_PRIVATE_REQUEST_BASE + 99999,
} VidyoClientPrivateRequest;

typedef enum VidyoClientPrivateConsoleLogConfiguration_
{
	VIDYO_CLIENT_PRIVATE_CONSOLE_LOG_CONFIGURATION_USE_EVENT = 100,	/* All logs sent to application via VIDYO_CLIENT_PRIVATE_OUT_EVENT_LOG */
} VidyoClientPrivateConsoleLogConfiguration;

/* Used for VIDYO_CLIENT_PRIVATE_IN_EVENT_LAYOUT */
typedef struct VidyoClientPrivateInEventLayout_
{
	VidyoUint layout_num;
	VidyoUint participants_limit_manual;
	VidyoUint participants_limit_render;
	VidyoUint participants_limit_safe;
	VidyoUint layout_wide;
} VidyoClientPrivateInEventLayout;

/* Used for VIDYO_CLIENT_PRIVATE_IN_EVENT_CHANGE_BANDWIDTHS */
typedef struct VidyoClientPrivateInEventChangeBandwidths_
{
	VidyoInt bandwidth_val;
	VidyoUint s_layers;
} VidyoClientPrivateInEventChangeBandwidths;

/* Used for VIDYO_CLIENT_PRIVATE_IN_EVENT_JOIN_SVCS */
typedef struct VidyoClientPrivateInEventJoinSvcs_
{
	char svcsAddress[MAX_URI_LEN];
	char svcsPort[SERVERPORT_SIZE];
	char conferenceName[MAX_URI_LEN];
	VidyoBool isSecured;
} VidyoClientPrivateInEventJoinSvcs;

// Used for VIDYO_CLIENT_PRIVATE_IN_EVENT_SET_PARTICIPANT_LIMIT
typedef struct VidyoClientPrivateInEventParticipantLimit_ 
{
	VidyoUint participantLimit;
}VidyoClientPrivateInEventParticipantLimit;


typedef struct VidyoClientPrivateInEventSelectCamera_
{
	/*! Index of camera */
	VidyoInt camera;
} VidyoClientPrivateInEventSelectCamera;

typedef struct VidyoClientPrivateInEventSelectSpeaker
{
	/*! Index of speaker */
	VidyoInt speaker;
} VidyoClientPrivateInEventSelectSpeaker;

/* Used by VIDYO_CLIENT_PRIVATE_IN_EVENT_GET_WINDOWS_EXT */
typedef struct VidyoClientPrivateInEventGetWindowsExt_
{
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event. 
									// this ID would be used in the multiple responses 
} VidyoClientPrivateInEventGetWindowsExt;


/* Used by VIDYO_CLIENT_PRIVATE_OUT_EVENT_GET_WINDOWS_EXT */
typedef struct VidyoClientPrivateOutEventGetWindowsExt_
{
	
	VidyoUint requestId;					// the request ID that originated this message 
											//	in VIDYO_CLIENT_PRIVATE_IN_EVENT_GET_WINDOWS_EXT
	VidyoUint totalResponseMessages;		// Total Number of response messages to this ID
	VidyoUint thisMessageNumberInSequance;	// 0 base counter to the number of messages. (second message in sequance of 10 would have this value as 1)
	VidyoUint totalNumApplicationWindows; 	// Total number of windows currently open
	VidyoUint numOfRecordsInThisMessage;	// The number of windows records in this message
	
	union{
		struct { 				//attributes specific to windows OS*/
			VidyoUint 					dwStyle[MAX_NUM_APP_WINDOWS];
			VidyoUint 					dwExStyle[MAX_NUM_APP_WINDOWS]; 
			VidyoWindowCapturerWindowId parentHandle[MAX_NUM_APP_WINDOWS];
			char 						WindowClassName[MAX_NUM_APP_WINDOWS][MAX_URI_LEN];	
		} Win32;

		struct {				//attribute specific to Mac OS
			VidyoUint 					sharingState[MAX_NUM_APP_WINDOWS];
			VidyoUint 					windowLayer[MAX_NUM_APP_WINDOWS];
		} MacOS;
	} os;

	VidyoWindowCapturerWindowId windowID[MAX_NUM_APP_WINDOWS];						// window handle
	char 						WindowName[MAX_NUM_APP_WINDOWS][MAX_URI_LEN];		// title 
	char 						WindowOwnerName[MAX_NUM_APP_WINDOWS][MAX_URI_LEN];	// owner name
	VidyoRect 					windowRect[MAX_NUM_APP_WINDOWS];					// window rect

} VidyoClientPrivateOutEventGetWindowsExt;


/* Used for VIDYO_CLIENT_PRIVATE_REQUEST_SNAP_WINDOW_RESIZE */
typedef struct VidyoClientPrivateRequestSnapWindowResize_
{
	VidyoUint x;
	VidyoUint y;
	VidyoUint width;
	VidyoUint height;
	VidyoClientResizingMethod sizingmethod;
	VidyoUint minWidth;
	VidyoUint minHeight;
	VidyoUint maxWidth;
	VidyoUint maxHeight;
	VidyoUint curWidth;
	VidyoUint curHeight;
	VidyoUint extraWidth;
	VidyoUint extraHeight;
} VidyoClientPrivateRequestSnapWindowResize;

/* Used for VIDYO_CLIENT_PRIVATE_REQUEST_GET_BANDWIDTH_INFO */
typedef enum VidyoClientPrivateBandwidthSource_
{
	VIDYO_CLIENT_PRIVATE_BANDWIDTH_SOURCE_VIDEO = 0,
	VIDYO_CLIENT_PRIVATE_BANDWIDTH_SOURCE_AUDIO,
	VIDYO_CLIENT_PRIVATE_BANDWIDTH_SOURCE_APP,
	VIDYO_CLIENT_PRIVATE_BANDWIDTH_SOURCE_TOTAL,
	VIDYO_CLIENT_PRIVATE_BANDWIDTH_SOURCE_MAX,
} VidyoClientPrivateBandwidthSource;
typedef enum VidyoClientPrivateBandwidthType_
{
	VIDYO_CLIENT_PRIVATE_BANDWIDTH_TYPE_AVAIL = 0,
	VIDYO_CLIENT_PRIVATE_BANDWIDTH_TYPE_ACTUAL,
	VIDYO_CLIENT_PRIVATE_BANDWIDTH_TYPE_MAX,
} VidyoClientPrivateBandwidthType;
typedef enum VidyoClientPrivateBandwidthDir_
{
	VIDYO_CLIENT_PRIVATE_BANDWIDTH_DIR_SEND = 0,
	VIDYO_CLIENT_PRIVATE_BANDWIDTH_DIR_RECV,
	VIDYO_CLIENT_PRIVATE_BANDWIDTH_DIR_MAX,
} VidyoClientPrivateBandwidthDir;
typedef struct VidyoClientPrivateRequestGetBandwidthInfo_
{
	VidyoUint
		rate[VIDYO_CLIENT_PRIVATE_BANDWIDTH_SOURCE_MAX]
			[VIDYO_CLIENT_PRIVATE_BANDWIDTH_TYPE_MAX]
			[VIDYO_CLIENT_PRIVATE_BANDWIDTH_DIR_MAX];
} VidyoClientPrivateRequestGetBandwidthInfo;

/* Used for VIDYO_CLIENT_PRIVATE_REQUEST_GET_VIDEO_FRAME_RATE_INFO */
typedef struct VidyoClientPrivateRequestGetVideoFrameRateInfo_
{
	VidyoUint captureFrameRate;
	VidyoUint encodeFrameRate;
	VidyoUint sendFrameRate;
} VidyoClientPrivateRequestGetVideoFrameRateInfo;

/* Used for VIDYO_CLIENT_PRIVATE_REQUEST_GET_RATE_SHAPER_INFO */
typedef enum VidyoClientPrivateRateShaperSource_
{
	VIDYO_CLIENT_PRIVATE_RATE_SHAPER_SOURCE_VIDEO = 0,
	VIDYO_CLIENT_PRIVATE_RATE_SHAPER_SOURCE_APP,
	VIDYO_CLIENT_PRIVATE_RATE_SHAPER_SOURCE_MAX,
} VidyoClientPrivateRateShaperSource;
typedef enum VidyoClientPrivateRateShaperPriority_
{
	VIDYO_CLIENT_PRIVATE_RATE_SHAPER_PRIORITY_NORMAL = 0,
	VIDYO_CLIENT_PRIVATE_RATE_SHAPER_PRIORITY_RETRANSMIT,
	VIDYO_CLIENT_PRIVATE_RATE_SHAPER_PRIORITY_MAX,
} VidyoClientPrivateRateShaperPriority;
typedef struct VidyoClientPrivateRequestGetRateShaperInfo_
{
	VidyoUint delay[VIDYO_CLIENT_PRIVATE_RATE_SHAPER_SOURCE_MAX][VIDYO_CLIENT_PRIVATE_RATE_SHAPER_PRIORITY_MAX];
	VidyoUint numPackets[VIDYO_CLIENT_PRIVATE_RATE_SHAPER_SOURCE_MAX][VIDYO_CLIENT_PRIVATE_RATE_SHAPER_PRIORITY_MAX];
	VidyoUint numFrames[VIDYO_CLIENT_PRIVATE_RATE_SHAPER_SOURCE_MAX][VIDYO_CLIENT_PRIVATE_RATE_SHAPER_PRIORITY_MAX];
	VidyoUint numDropped[VIDYO_CLIENT_PRIVATE_RATE_SHAPER_SOURCE_MAX][VIDYO_CLIENT_PRIVATE_RATE_SHAPER_PRIORITY_MAX];
} VidyoClientPrivateRequestGetRateShaperInfo;

typedef enum VidyoClientPrivateVideoEncoderLayers_
{
	VIDYO_CLIENT_PRIVATE_VIDEO_ENCODER_LAYER_NONE = 0,
	VIDYO_CLIENT_PRIVATE_VIDEO_ENCODER_LAYER_ONE,
	VIDYO_CLIENT_PRIVATE_VIDEO_ENCODER_LAYER_TWO,
	VIDYO_CLIENT_PRIVATE_VIDEO_ENCODER_LAYER_THREE,
} VidyoClientPrivateVideoEncoderLayers;

typedef struct VidyoClientPrivateRequestGetVideoEncoderLayers_
{
	VidyoClientPrivateVideoEncoderLayers numTLayers;	// Number of temporal video layers
	VidyoClientPrivateVideoEncoderLayers numSLayers;	// Number of spatial video layers
} VidyoClientPrivateRequestGetVideoEncoderLayers;

typedef struct VidyoClientPrivateRequestGetAudioStats_
{
	VidyoInt echoCoupling;		// Echo coupling
} VidyoClientPrivateRequestGetAudioStats;

/* Used for VIDYO_CLIENT_PRIVATE_REQUEST_GET_OR_SET_WINDOW_SHARES */
typedef struct VidyoClientPrivateRequestGetOrSetWindowShares_
{
	char remoteAppUri[MAX_REMOTE_SHARE_APP][MAX_URI_LEN];
	char remoteAppName[MAX_REMOTE_SHARE_APP][MAX_URI_LEN];
	wchar_t remoteAppNameW[MAX_REMOTE_SHARE_APP][MAX_URI_LEN];
	VidyoInt numApp;
	VidyoInt currApp;
	char eventUri[MAX_URI_LEN];
	VidyoInt newApp;
} VidyoClientPrivateRequestGetOrSetWindowShares;

/* Used for VIDYO_CLIENT_PRIVATE_REQUEST_GET_SIGNED_INFO */
typedef struct VidyoClientPrivateRequestSignedInfo_
{
	VidyoBool enableShowDialpad;
	VidyoBool enableShowStartmeeting;
} VidyoClientPrivateRequestSignedInfo;

/* TODO: document purpose of this type */
typedef enum VidyoClientConnectionPath_
{
	VIDYO_CLIENT_CONNECTION_PATH_NONE,
	VIDYO_CLIENT_CONNECTION_PATH_DIRECT,
	VIDYO_CLIENT_CONNECTION_PATH_PROXY,
	VIDYO_CLIENT_CONNECTION_PATH_WEBPROXY,
	VIDYO_CLIENT_CONNECTION_PATH_VIDYOPROXY_AND_WEBPROXY,
} VidyoClientConnectionPath;

typedef enum VidyoClientRunningStateEnum_
{
    VIDYO_CLIENT_UNINITIALIZED,
	VIDYO_CLIENT_INITIALIZED,
	VIDYO_CLIENT_STARTED,
	VIDYO_CLIENT_RUNNING,
	VIDYO_CLIENT_STOPPING,
} VidyoClientRunningStateEnum;

/* Used for VIDYO_CLIENT_PRIVATE_REQUEST_GET_AUDIO_ENERGY_INFO */
typedef struct VidyoClientPrivateRequestAudioEnergyInfo_
{
	VidyoInt rendererEnergy;
	VidyoInt capturerEnergy;
} VidyoClientPrivateRequestAudioEnergyInfo;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_PRIVATE_REQUEST_GET_DEVICES
		+ #VIDYO_CLIENT_PRIVATE_REQUEST_SET_DEVICES
	- Passed in field state of following structs:
		+ #VidyoClientPrivateRequestGetDevices
		+ #VidyoClientPrivateRequestSetDevices
*/
typedef struct VidyoClientPrivateDeviceList_
{
	/*!
		Name of the device.
	*/
	VidyoUint8 deviceName[DEVICE_NAME_SIZE];
	/*!
		State of device - VIDYO_TRUE (enabled and hence usable) or VIDYO_FALSE (disable and hence not usable).
	*/
	VidyoBool deviceState;
} VidyoClientPrivateDeviceList;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_PRIVATE_REQUEST_GET_DEVICES

*/
typedef struct VidyoClientPrivateRequestGetDevices_
{
	/*!
		Kind of device for which this request is made (IN).  @see VidyoClientDeviceType.
		Please note that only device type = VIDYO_CLIENT_DEVICE_TYPE_VIDEO is supported now
	*/
	VidyoClientDeviceType deviceType;
	/*!
		Number of device in deviceList (OUT).
	*/
	VidyoUint numDevices;
	/*!
		Index on device list that user selected (OUT).
		Value set UINT_MAX means no device is selected.
	*/
	VidyoUint currentSelection;
	/*! Device list (OUT) */
	VidyoClientPrivateDeviceList deviceList[MAX_DEVICE_NUMBER];
} VidyoClientPrivateRequestGetDevices;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_PRIVATE_REQUEST_SET_DEVICES

*/
typedef struct VidyoClientPrivateRequestSetDevices_
{
	/*!
		Kind of device for which this request is made (IN).  @see VidyoClientDeviceType.
		Please note that only device type = VIDYO_CLIENT_DEVICE_TYPE_VIDEO is supported now
	*/
	VidyoClientDeviceType deviceType;
	/*!
		Number of device in deviceList (IN).
	*/
	VidyoUint numDevices;
	/*!
		Index on device list that user selected (IN).
		Value set UINT_MAX means no device is selected.
	*/
	VidyoUint currentSelection;
	/*! Device list (IN) */
	VidyoClientPrivateDeviceList deviceList[MAX_DEVICE_NUMBER];
} VidyoClientPrivateRequestSetDevices;

/* Used for VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_STATISTIC_AT */
typedef VidyoClientParticipantStatistics VidyoClientPrivateRequestParticipantStatistic;

typedef enum
{
	VidyoClientPrivateParticipantTypeNone,
	VidyoClientPrivateParticipantTypeGuest,
	VidyoClientPrivateParticipantTypeRecorder,
	VidyoClientPrivateParticipantTypeLegacy,
	VidyoClientPrivateParticipantTypeControl
} VidyoClientPrivateParticipantType;

typedef enum
{
	VidyoClientPrivateParticipantRoleNone,
	VidyoClientPrivateParticipantRoleOwner,
	VidyoClientPrivateParticipantRoleAdmin,
	VidyoClientPrivateParticipantRoleModerator
} VidyoClientPrivateParticipantRole;


/* Used for VIDYO_CLIENT_PRIVATE_REQUEST_GET_PARTICIPANT_DETAILS_AT */
typedef struct VidyoClientPrivateRequestParticipantDetails_
{
	char uri[MAX_URI_LEN];
	char name[USERID_SIZE];
	char participantID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];		// Entity ID of the participant
	char entityID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];		// Entity ID of the participant
    VidyoClientPrivateParticipantType participantType;		// Is this user joined as guest, recorder, legacy
	VidyoClientPrivateParticipantRole participantRole;		//whether normal , owner or special right
    VidyoBool isVideoBlocked;
    VidyoBool isAudioBlocked;
    VidyoBool isShareBlocked;
} VidyoClientPrivateRequestParticipantDetails;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_PRIVATE_OUT_EVENT_PORTAL_COMMUNICATION_STATUS
*/
typedef struct VidyoClientPrivateOutEventPortalCommunicationStatus_
{
	/*! Portal Communication status 
	
	0 - Portal cannot be contacted for search, control meeting etc
	1 - Portal can be contacted for search, control meeting etc
	*/ 
    VidyoBool status;
	/*! Status of token based communication with portal.
		
		0 - Token is not available for communication with Portal.
		1 - Token is available for communication with Portal.
	*/
	VidyoBool useToken;

} VidyoClientPrivateOutEventPortalCommunicationStatus;

/*! Reason for Signin updates
	- Used by following out events:
		+ #VidyoClientPrivateOutEventSignInUpdate
*/
typedef enum {
	HTTP_TIMEOUT_RETRYING_HTTPS,		/* Attempt to connect non-secure (http) portal is timedout. So retrying on secure (https) portal */
	HTTP_REDIRECT_TO_HTTPS,				/* Attempt to connect non-secure (http) portal is redirected to secure portal. So retrying on redirected portal */
} SignInUpdateReason;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_PRIVATE_OUT_EVENT_SIGNIN_UPDATE
*/
typedef struct VidyoClientPrivateOutEventSignInUpdate_
{
	/*! Reason for Signin updates 
	*/ 
    SignInUpdateReason reason;

} VidyoClientPrivateOutEventSignInUpdate;


/*! Reason for Signin updates
	- Used by following out events:
		+ #VidyoClientPrivateOutEventLoginStarted
*/
typedef enum {
	EXTERNAL,	/* Login request received from external application e.g. login using userportal browser */
	AUTOMATIC,	/* Relogin using the previously provided credentials */
} LoginType;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_PRIVATE_OUT_EVENT_LOGIN_STARTED
*/
typedef struct VidyoClientPrivateOutEventLoginStarted_
{
	/*! Login Type */
	LoginType loginType;
	/*! Portal URI */
	char portalUri[URI_LEN];
	/*! User name */
	char userName[USERID_SIZE];
	/*! Normal user login or guest user login */
	VidyoBool guestLogin;

} VidyoClientPrivateOutEventLoginStarted;


/*! Reason for Signin updates
	- Used by following out events:
		+ #VidyoClientPrivateOutEventNoLoginCredential
*/
typedef enum {
	NO_LOGIN_CREDENTIAL,	/* Could not login as the credential are not present. e.g. userid, portal address, PAK */
	OLD_PORTAL_VERSION,		/* Might be able to connect to portal. Since the portal version is old, authentication token cannot be used for interfaces */
	AUTO_LOGIN_DISABLED,	/* Automatic login is disabled */
} NoCredentialReason;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_PRIVATE_OUT_EVENT_NO_LOGIN_CREDENTIAL
*/
typedef struct VidyoClientPrivateOutEventNoLoginCredential_
{
	/*! Reason for no credential out event
	*/ 
    NoCredentialReason reason;

} VidyoClientPrivateOutEventNoLoginCredential;


/*! Type of state change on device
	- Used by following out events:
		+ #VidyoClientPrivateOutEventKioskDeviceStateChanged
*/
typedef enum {
	DEVICE_AVAILABLE,			/* The device is available for use */
	DEVICE_NOT_AVAILABLE,		/* The device is not available for use */
} VidyoClientDeviceStateChangeType;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_PRIVATE_OUT_EVENT_KIOSK_DEVICE_STATE_CHANGED
*/
typedef struct VidyoClientPrivateOutEventKioskDeviceStateChanged_
{
	/*!
		Kind of device, whose state is changed.  @see VidyoClientDeviceType.
	*/
	VidyoClientDeviceType deviceType;
	/*!
		The type of state change had happened. @see VidyoClientDeviceStateChangeType.
	*/
	VidyoClientDeviceStateChangeType changeType;
	/*! Name of the device that is changed. */
	VidyoUint8 deviceName[DEVICE_NAME_SIZE];
} VidyoClientPrivateOutEventKioskDeviceStateChanged;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_PRIVATE_OUT_EVENT_LOW_MASTER_VOLUME
*/
typedef struct VidyoClientPrivateOutEventLowMasterVolume_
{
	/*!
		Kind of device, whose master volume may be is too low.  @see VidyoClientDeviceType.
	*/
	VidyoClientDeviceType deviceType;
	/*!
		The current value of master volume - retrieved from device.
	*/
	VidyoUint masterVolume;
	/*! Name of the device that is used now. */
    VidyoUint8 deviceName[DEVICE_NAME_SIZE];
} VidyoClientPrivateOutEventLowMasterVolume;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_PRIVATE_REQUEST_SET_CALL_WINDOW_AUTO_CLEAN
*/
typedef struct VidyoClientPrivateRequestSetCallWindowAutoClean_
{
	/*!
		Do we auto clean - VIDYO_TRUE (yes) or VIDYO_FALSE (no and the default value).
	*/
	VidyoBool cleanOrNot;
}  VidyoClientPrivateRequestSetCallWindowAutoClean;

/* Start of type definitions used in SOAP interface */

typedef enum VidyoClientPrivateSoapRequestType_
{
    VIDYO_CLIENT_PRIVATE_SOAP_CLIENT_VERSION = 1,
	VIDYO_CLIENT_PRIVATE_SOAP_FILE_DOWNLOAD,
	VIDYO_CLIENT_PRIVATE_SOAP_REGISTER_LICENSE,
	VIDYO_CLIENT_PRIVATE_SOAP_BROWSER_ACCESS_KEY,
	VIDYO_CLIENT_PRIVATE_SOAP_JOIN_CONFERENCE,			// Uses EntityID of the party to send request to join conference
    VIDYO_CLIENT_PRIVATE_SOAP_JOIN_CONFERENCE_BY_NAME,	// Uses Display Name of the party to send request to join conference
	VIDYO_CLIENT_PRIVATE_SOAP_START_MY_CONFERENCE,		// Request to join default conference room of a member
	VIDYO_CLIENT_PRIVATE_SOAP_LOGIN,					// Request to sign-in to a portal URL using username and password
	VIDYO_CLIENT_PRIVATE_SOAP_LOGOUT,					// Request to sign-out of the portal where user is signed-in
	VIDYO_CLIENT_PRIVATE_SOAP_LINK_ENDPOINT,
	VIDYO_CLIENT_PRIVATE_SOAP_SEARCH,					// Search portal DB using an optional search string to get details
														// all users.
	VIDYO_CLIENT_PRIVATE_SOAP_SEARCH_BY_ENTITY_ID,		// Uses a given entityID to search portal DB
	VIDYO_CLIENT_PRIVATE_SOAP_SEARCH_BY_MY_ENTITY_ID,	// Uses entityID of user who signed-in to do search portal DB
	VIDYO_CLIENT_PRIVATE_SOAP_GET_ENTITY_BY_ENTITY_ID,
	VIDYO_CLIENT_PRIVATE_SOAP_SEARCH_MY_CONTACT,		// Search portal DB to get details all user in my contact
	VIDYO_CLIENT_PRIVATE_SOAP_SEARCH_MY_CONTACT_ENTITY_ID,// Search portal DB to get entityId of all user in my contact
	VIDYO_CLIENT_PRIVATE_SOAP_DIRECT_CALL,				// Uses EntityID of the party to send direct call request
	VIDYO_CLIENT_PRIVATE_SOAP_DIRECT_CALL_BY_NAME,		// Uses Display Name of the party to send direct call request
	VIDYO_CLIENT_PRIVATE_SOAP_MY_ACCOUNT,				// Request to get details of my account
	VIDYO_CLIENT_PRIVATE_SOAP_ADD_TO_MY_CONTACTS,		// Request to add a user to my contact
	VIDYO_CLIENT_PRIVATE_SOAP_REMOVE_FROM_MY_CONTACTS,	// Request to remove a user from my contact
	VIDYO_CLIENT_PRIVATE_SOAP_INVITE_TO_CONFERENCE,		// Request to invite a user to a conference room
	VIDYO_CLIENT_PRIVATE_SOAP_GET_PARTICIPANTS,			// Request to get participants of a conference call 
	VIDYO_CLIENT_PRIVATE_SOAP_CREATE_ROOM,		// Request to create a conference room
	VIDYO_CLIENT_PRIVATE_SOAP_DELETE_ROOM,		// Request to delete a conference room
	VIDYO_CLIENT_PRIVATE_SOAP_CREATE_ROOM_PIN,	// Request to create PIN for a conference room
	VIDYO_CLIENT_PRIVATE_SOAP_REMOVE_ROOM_PIN,	// Request to remove/delete a conference room PIN
	VIDYO_CLIENT_PRIVATE_SOAP_LOCK_CURRENT_ACTIVE_ROOM,  // Request to lock room on which user is connected to
	VIDYO_CLIENT_PRIVATE_SOAP_LOCK_ROOM,		// Request to lock a conference room
	VIDYO_CLIENT_PRIVATE_SOAP_UNLOCK_CURRENT_ACTIVE_ROOM,  // Request to unlock room on which user is connected to
	VIDYO_CLIENT_PRIVATE_SOAP_UNLOCK_ROOM,		// Request to unlock a conference room
	VIDYO_CLIENT_PRIVATE_SOAP_DROP_PARTICIPANT,	// Request to drop a participant from conference room
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_VERSION,   // Request to get portal version number
	VIDYO_CLIENT_PRIVATE_SOAP_MUTE_AUDIO,		// Mute audio request for a participant in conference call
	VIDYO_CLIENT_PRIVATE_SOAP_UNMUTE_AUDIO,		// Unmute audio request for a participant in conference call
	VIDYO_CLIENT_PRIVATE_SOAP_START_VIDEO,		// Start video request for a participant in conference call
	VIDYO_CLIENT_PRIVATE_SOAP_STOP_VIDEO,		// Stop video (privacy) request for a participant in conference call
	VIDYO_CLIENT_PRIVATE_SOAP_GET_USER_NAME,    // Request to get user name as entered in portal DB
	
	VIDYO_CLIENT_PRIVATE_SOAP_CREATE_ROOM_URL,	// Create room URL for a conference room owned by a member
	VIDYO_CLIENT_PRIVATE_SOAP_REMOVE_ROOM_URL,	// Remove room URL for a conference room owned by a member
	VIDYO_CLIENT_PRIVATE_SOAP_UPDATE_PASSWORD,  // Update password
	VIDYO_CLIENT_PRIVATE_SOAP_CREATE_WEBCAST_URL,//Create webcast URL for a conference
	VIDYO_CLIENT_PRIVATE_SOAP_REMOVE_WEBCAST_URL,//Remove webcast URL for a conference
	VIDYO_CLIENT_PRIVATE_SOAP_GET_WEBCAST_URL,   //Get webcast URL for a conference 
	VIDYO_CLIENT_PRIVATE_SOAP_CREATE_WEBCAST_PIN,//Create webcast PIN for a conference
	VIDYO_CLIENT_PRIVATE_SOAP_REMOVE_WEBCAST_PIN,//Remove webcast PIN for a conference
	VIDYO_CLIENT_PRIVATE_SOAP_CREATE_MODERATOR_PIN,//Create moderator PIN of a conference
	VIDYO_CLIENT_PRIVATE_SOAP_REMOVE_MODERATOR_PIN,//Remove moderator PIN of a conference
	VIDYO_CLIENT_PRIVATE_SOAP_CREATE_SCHEDULED_ROOM, //Create scheduled room for a conference
	VIDYO_CLIENT_PRIVATE_SOAP_GET_INVITE_CONTENT, //Get invite content for a conference
	VIDYO_CLIENT_PRIVATE_SOAP_GET_CONFERENCEID,   // Get conference id of a conference
	VIDYO_CLIENT_PRIVATE_SOAP_GENERATE_AUTHTOKEN, // Generate authentication token for this endpoint
	VIDYO_CLIENT_PRIVATE_SOAP_GET_PORTALFEATURES, // Get Portal Features
    VIDYO_CLIENT_PRIVATE_SOAP_GET_PORTALFEATURES_ANONYMOUS, // Get Portal Features ANONYMOUS
	VIDYO_CLIENT_PRIVATE_SOAP_JOIN_IPC_CONFERENCE, // Request to Join IPC Conference
	VIDYO_CLIENT_PRIVATE_SOAP_GUEST_LINK,
	VIDYO_CLIENT_PRIVATE_SOAP_JOIN_WITH_ROOMKEY,
	VIDYO_CLIENT_PRIVATE_SOAP_GET_ENTITY_BY_ROOMKEY, // For GetEntityByRoomKeyRequest & GetEntityByRoomKeyResponse
	VIDYO_CLIENT_PRIVATE_SOAP_GUEST_CLIENT_VERSION_ON_SERVER, //Use public version of this request event
	VIDYO_CLIENT_PRIVATE_SOAP_GET_LOGIN_WELCOME_BANNER,//to get login banner and welcome banner
	VIDYO_CLIENT_PRIVATE_SOAP_GET_MODERATOR_URL,//to get moderator url
	VIDYO_CLIENT_PRIVATE_SOAP_GET_ROOM_ACCESS_OPTIONS, //Get the room access options

	VIDYO_CLIENT_PRIVATE_SOAP_START_RECORDING,
	VIDYO_CLIENT_PRIVATE_SOAP_PAUSE_RECORDING,
	VIDYO_CLIENT_PRIVATE_SOAP_RESUME_RECORDING,
	VIDYO_CLIENT_PRIVATE_SOAP_STOP_RECORDING,
	VIDYO_CLIENT_PRIVATE_SOAP_GET_RECORDINGID,
	VIDYO_CLIENT_PRIVATE_SOAP_GET_RECORDING_PROFILES,
	VIDYO_CLIENT_PRIVATE_SOAP_GET_PORTAL_PREFIX,

	VIDYO_CLIENT_PRIVATE_SOAP_LECTURE_CLEAR_RAISE_HAND, //Use public version of this request event
	VIDYO_CLIENT_PRIVATE_SOAP_SET_ENDPOINT_DETAILS,
	VIDYO_CLIENT_PRIVATE_SOAP_LOGOUT_ALL_OTHER_SESSIONS,					// Request to sign-out other logins
	VIDYO_CLIENT_PRIVATE_SOAP_GET_PARTICIPANTS_EX,			// Request to get participants of a conference call 
	VIDYO_CLIENT_PRIVATE_SOAP_GET_CHANGE_PASSWORD_HTML_URL_WITH_TOKEN,			//Request to get the change password HTML page URL
	VIDYO_CLIENT_PRIVATE_SOAP_DROP_ALL,  // Request to drop all participants from current conference room where the user is connected to
	VIDYO_CLIENT_PRIVATE_SOAP_CONTROL_AUDIO_SERVER_ALL,  // Request to server mute all participants of current conference room where the user is connected to
	VIDYO_CLIENT_PRIVATE_SOAP_MUTE_AUDIO_CLIENT_ALL,  // Request to client/user mute (silence) all participants of current conference room where the user is connected to
	VIDYO_CLIENT_PRIVATE_SOAP_CONTROL_PRIVACY_SERVER_ALL,  // Request to turn on server privacy for all participants of current conference room where the user is connected to
	VIDYO_CLIENT_PRIVATE_SOAP_PRIVACY_ON_CLIENT_ALL,  // Request to turn on client/user privacy for all participants of current conference room where the user is connected to

	/* The following interfaces are not implemented. */	
	VIDYO_CLIENT_PRIVATE_SOAP_UPDATE_LANGUAGE,	// Update language selection at portal
	VIDYO_CLIENT_PRIVATE_SOAP_SET_MEMBER_MODE,	// Set member mode to Away, don't disturb & Available
	VIDYO_CLIENT_PRIVATE_SOAP_INVALID,	//always the last
} VidyoClientPrivateSoapRequestType;

typedef enum
{
	VIDYO_CLIENT_PRIVATE_SOAP_CLIENTTYPE_M = VIDYO_CLIENT_CLIENTTYPE_M,
	VIDYO_CLIENT_PRIVATE_SOAP_CLIENTTYPE_V = VIDYO_CLIENT_CLIENTTYPE_V,
	VIDYO_CLIENT_PRIVATE_SOAP_CLIENTTYPE_W = VIDYO_CLIENT_CLIENTTYPE_W,
	VIDYO_CLIENT_PRIVATE_SOAP_CLIENTTYPE_R = VIDYO_CLIENT_CLIENTTYPE_R,
	VIDYO_CLIENT_PRIVATE_SOAP_CLIENTTYPE_L = VIDYO_CLIENT_CLIENTTYPE_L,
	VIDYO_CLIENT_PRIVATE_SOAP_CLIENTTYPE_S = VIDYO_CLIENT_CLIENTTYPE_S,
	VIDYO_CLIENT_PRIVATE_SOAP_CLIENTTYPE_U = VIDYO_CLIENT_CLIENTTYPE_U,
	VIDYO_CLIENT_PRIVATE_SOAP_CLIENTTYPE_T = VIDYO_CLIENT_CLIENTTYPE_T, //SL5 64
	VIDYO_CLIENT_PRIVATE_SOAP_CLIENTTYPE_X = VIDYO_CLIENT_CLIENTTYPE_X, //Ubuntu 64
	VIDYO_CLIENT_PRIVATE_SOAP_CLIENTTYPE_A = VIDYO_CLIENT_CLIENTTYPE_A, //Android
	VIDYO_CLIENT_PRIVATE_SOAP_CLIENTTYPE_I = VIDYO_CLIENT_CLIENTTYPE_I, //iOS
} VidyoClientPrivateSoapClientType;

typedef enum
{
	VIDYO_CLIENT_PRIVATE_SOAP_DOWNLOAD_START = 1,
	VIDYO_CLIENT_PRIVATE_SOAP_DOWNLOAD_PROGRESS,
	VIDYO_CLIENT_PRIVATE_SOAP_DOWNLOAD_FINISHED,
	VIDYO_CLIENT_PRIVATE_SOAP_DOWNLOAD_CANCEL,
	VIDYO_CLIENT_PRIVATE_SOAP_DOWNLOAD_ERROR,
	VIDYO_CLIENT_PRIVATE_SOAP_OPEN_AND_DOWNLOAD_START
} VidyoClientPrivateSoapFileDownloadState;

typedef enum VidyoClientPrivateSoapError_
{
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_NONE 					= VIDYO_CLIENT_ERROR_NONE, 
	//curl errors 1-83
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_COULD_NOT_RESOLVE_PROXY = VIDYO_CLIENT_ERROR_TCP_COULD_NOT_RESOLVE_PROXY,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_COULD_NOT_RESOLVE_HOST 	= VIDYO_CLIENT_ERROR_TCP_COULD_NOT_RESOLVE_HOST,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_COULD_NOT_CONNECT 		= VIDYO_CLIENT_ERROR_TCP_COULD_NOT_CONNECT,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_REMOTE_ACCESS_DENIED 	= VIDYO_CLIENT_ERROR_TCP_REMOTE_ACCESS_DENIED,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_HTTP_RETURNED_ERROR 	= VIDYO_CLIENT_ERROR_TCP_HTTP_RETURNED_ERROR,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_OPERATION_TIMED_OUT 	= VIDYO_CLIENT_ERROR_TCP_OPERATION_TIMED_OUT,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_SSL_CONNECT_ERROR 		= VIDYO_CLIENT_ERROR_TCP_SSL_CONNECT_ERROR,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_TOO_MANY_REDIRECTS 		= VIDYO_CLIENT_ERROR_TCP_TOO_MANY_REDIRECTS,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_PEER_FAILED_VERIFICATION = VIDYO_CLIENT_ERROR_TCP_PEER_FAILED_VERIFICATION,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_GOT_NOTHING 			= VIDYO_CLIENT_ERROR_TCP_GOT_NOTHING,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_SSL_ENGINE_NOT_FOUND 	= VIDYO_CLIENT_ERROR_TCP_SSL_ENGINE_NOT_FOUND,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_SSL_ENGINE_SET_FAILED 	= VIDYO_CLIENT_ERROR_TCP_SSL_ENGINE_SET_FAILED,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_SSL_CERT_PROBLEM 		= VIDYO_CLIENT_ERROR_TCP_SSL_CERT_PROBLEM,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_SSL_CIPHER 				= VIDYO_CLIENT_ERROR_TCP_SSL_CIPHER,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_SSL_CACERT 				= VIDYO_CLIENT_ERROR_TCP_SSL_CACERT, // CURLE_SSL_CACERT - Peer certificate cannot be authenticated with known CA certificates.
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_BAD_CONTENT_ENCODING 	= VIDYO_CLIENT_ERROR_TCP_BAD_CONTENT_ENCODING,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_FILE_SIZE_EXCEEDED 		= VIDYO_CLIENT_ERROR_TCP_FILE_SIZE_EXCEEDED,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_SSL_ENGINE_INIT_FAILED 	= VIDYO_CLIENT_ERROR_TCP_SSL_ENGINE_INIT_FAILED,
	VIDYO_CLIENT_PRIVATE_SOAP_ERROR_SSL_ISSUER_ERROR 		= VIDYO_CLIENT_ERROR_TCP_SSL_ISSUER_ERROR,

	//shifted VIDYO_CLIENT_PRIVATE_VCSOAP_ERROR_CURL_INIT = 91,
    //shifted VIDYO_CLIENT_PRIVATE_VCSOAP_ERROR_NO_PORTAL_ADDRESS = 92,
	VIDYO_CLIENT_PRIVATE_VCSOAP_ERROR_INTERNAL 				= VIDYO_CLIENT_ERROR_INTERNAL_REQUEST,
	VIDYO_CLIENT_PRIVATE_VCSOAP_ERROR_RESPONSE 				= VIDYO_CLIENT_ERROR_INTERNAL_RESPONSE,
	VIDYO_CLIENT_PRIVATE_VCSOAP_ERROR_COULD_NOT_LINK 		= VIDYO_CLIENT_ERROR_INTERNAL_COULD_NOT_LINK,
	VIDYO_CLIENT_PRIVATE_VCSOAP_ERROR_LOGIN_CANCELED 		= VIDYO_CLIENT_ERROR_INTERNAL_LOGIN_CANCELED,
	VIDYO_CLIENT_PRIVATE_VCSOAP_ERROR_LOGIN_OLD_SERVER 		= VIDYO_CLIENT_ERROR_INTERNAL_LOGIN_OLD_SERVER, // mobile only, which doesn't support 2.0.4 server
	VIDYO_CLIENT_PRIVATE_VCSOAP_ERROR_CURL_INIT 			= VIDYO_CLIENT_ERROR_INTERNAL_CURL_INIT,
    VIDYO_CLIENT_PRIVATE_VCSOAP_ERROR_NO_PORTAL_ADDRESS 	= VIDYO_CLIENT_ERROR_INTERNAL_NO_PORTAL_ADDRESS,
	
	VIDYO_CLIENT_PRIVATE_VCSOAP_HTTP_ERROR = 0xffff // Should be the last and highest value	
} VidyoClientPrivateSoapError;

typedef enum VidyoClientPrivateHttpError_
{
	VIDYO_CLIENT_PRIVATE_SOAP_HTTP_ERROR_NONE 							= VIDYO_CLIENT_ERROR_HTTP_200_OK,
	VIDYO_CLIENT_PRIVATE_ERROR_HTTP_301_REDIRECT 						= VIDYO_CLIENT_ERROR_HTTP_301_REDIRECT,
	VIDYO_CLIENT_PRIVATE_ERROR_HTTP_302_REDIRECT 						= VIDYO_CLIENT_ERROR_HTTP_302_REDIRECT,
	VIDYO_CLIENT_PRIVATE_ERROR_HTTP_401_UNAUTHORIZED 					= VIDYO_CLIENT_ERROR_HTTP_401_UNAUTHORIZED,
	VIDYO_CLIENT_PRIVATE_ERROR_HTTP_407_PROXY_AUTHENTICATION_REQUIRED 	= VIDYO_CLIENT_ERROR_HTTP_407_PROXY_AUTHENTICATION_REQUIRED,
	VIDYO_CLIENT_PRIVATE_ERROR_HTTP_407_TIMED_OUT					 	= VIDYO_CLIENT_ERROR_HTTP_408_TIMED_OUT,
} VidyoClientPrivateHttpError;

typedef enum VidyoClientPrivateSoapFault_
{
 	VIDYO_CLIENT_PRIVATE_FAULT_NONE = VIDYO_CLIENT_SOAP_FAULT_NONE,
	VIDYO_CLIENT_PRIVATE_FAULT_INVALID_ARGUMENT = VIDYO_CLIENT_SOAP_FAULT_INVALID_ARGUMENT,
	VIDYO_CLIENT_PRIVATE_FAULT_NOT_LICENSED = VIDYO_CLIENT_SOAP_FAULT_NOT_LICENSED,
	VIDYO_CLIENT_PRIVATE_FAULT_GENERAL = VIDYO_CLIENT_SOAP_FAULT_GENERAL,
	VIDYO_CLIENT_PRIVATE_FAULT_CONFERENCE_LOCKED = VIDYO_CLIENT_SOAP_FAULT_CONFERENCE_LOCKED,
	VIDYO_CLIENT_PRIVATE_FAULT_LICENSE_EXPIRED = VIDYO_CLIENT_SOAP_FAULT_LICENSE_EXPIRED,
	VIDYO_CLIENT_PRIVATE_FAULT_WRONG_PIN = VIDYO_CLIENT_SOAP_FAULT_WRONG_PIN,
	VIDYO_CLIENT_PRIVATE_FAULT_RESOURCES_NOT_AVAILABLE = VIDYO_CLIENT_SOAP_FAULT_RESOURCES_NOT_AVAILABLE,
	VIDYO_CLIENT_PRIVATE_FAULT_ACCESS_RESTRICTED = VIDYO_CLIENT_SOAP_FAULT_ACCESS_RESTRICTED,
	VIDYO_CLIENT_PRIVATE_SOAP_FAULT_USER_NOT_BOUND = VIDYO_CLIENT_SOAP_FAULT_USER_NOT_BOUND,
	VIDYO_CLIENT_PRIVATE_SOAP_FAULT_ROOM_IS_FULL = VIDYO_CLIENT_SOAP_FAULT_ROOM_IS_FULL,
	VIDYO_CLIENT_PRIVATE_SOAP_FAULT_PORTAL_PREFIX_NOT_CONFIGURED  = VIDYO_CLIENT_SOAP_FAULT_PORTAL_PREFIX_NOT_CONFIGURED,
	VIDYO_CLIENT_PRIVATE_SOAP_FAULT_CONTROL_MEETING_FAILED  = VIDYO_CLIENT_SOAP_FAULT_CONTROL_MEETING_FAILED,
}VidyoClientPrivateSoapFault;

typedef struct VidyoClientPrivateSoapInEventMandatoryPart_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.
} VidyoClientPrivateSoapInEventMandatoryPart;

typedef struct VidyoClientPrivateSoapOutEventMandatoryPart_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.
} VidyoClientPrivateSoapOutEventMandatoryPart;

typedef struct VidyoClientPrivateSoapInEventClientVersion_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientClientType clientType;
	VidyoBool userInitiated;
} VidyoClientPrivateSoapInEventClientVersion;

typedef struct VidyoClientPrivateSoapOutEventClientVersion_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoBool userInitiated;
	char currentTag[VIDYO_CLIENT_PRIVATE_SOAP_CURRENT_TAG_SIZE];
	char installerUri[VIDYO_CLIENT_PRIVATE_SOAP_INSTALLER_URI_SIZE];
} VidyoClientPrivateSoapOutEventClientVersion;

typedef struct VidyoClientPrivateSoapInEventFileDownload_
{
	VidyoUint typeRequest; 
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char installerUri[VIDYO_CLIENT_PRIVATE_SOAP_INSTALLER_URI_SIZE];
	VidyoClientPrivateSoapFileDownloadState stateDownload; 
	FILE* hndlFileDownload;
	wchar_t installerPathW[VIDYO_CLIENT_PRIVATE_SOAP_INSTALLER_PATH_SIZE];
} VidyoClientPrivateSoapInEventFileDownload;

typedef struct VidyoClientPrivateSoapOutEventFileDownload_
{
	VidyoUint typeRequest; 
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapFileDownloadState stateDownload;
	double progrDownload;
	FILE* hndlFileDownload;
	wchar_t installerPathW[VIDYO_CLIENT_PRIVATE_SOAP_INSTALLER_PATH_SIZE];
} VidyoClientPrivateSoapOutEventFileDownload;

typedef struct VidyoClientPrivateSoapInEventRegisterLicense_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char hostname[VIDYO_CLIENT_PRIVATE_SOAP_HOSTNAME_SIZE];
} VidyoClientPrivateSoapInEventRegisterLicense;

typedef struct VidyoClientPrivateSoapOutEventRegisterLicense_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char LAC[VIDYO_CLIENT_PRIVATE_SOAP_LAK_SIZE];
	VidyoBool OutOfLicenses;
	VidyoUint vmConnectionPath;
} VidyoClientPrivateSoapOutEventRegisterLicense;

typedef struct VidyoClientPrivateSoapInEventBrowserAccessKey_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

} VidyoClientPrivateSoapInEventBrowserAccessKey;

typedef struct VidyoClientPrivateSoapOutEventBrowserAccessKey_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char BAK[VIDYO_CLIENT_PRIVATE_SOAP_BAK_SIZE];
} VidyoClientPrivateSoapOutEventBrowserAccessKey;


typedef enum VidyoClientPrivatePortalCdrVersion_
{
	VIDYO_CLIENT_PRIVATE_PORTAL_CDR_VERSION_2_0=1,	// Portal CDR version is 2.0 or older
	VIDYO_CLIENT_PRIVATE_PORTAL_CDR_VERSION_2_1,	// Portal CDR version is 2.1
} VidyoClientPrivatePortalCdrVersion;

typedef enum VidyoClientPrivateSoapPortalFeaturesNames_
{
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_SCHEDULED_ROOM=VIDYO_CLIENT_PORTAL_FEATURE_NAME_SCHEDULED_ROOM,	// Scheduled room
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_GUEST = VIDYO_CLIENT_PORTAL_FEATURE_NAME_GUEST,					// Guest
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_IPC_OUTBOUND = VIDYO_CLIENT_PORTAL_FEATURE_NAME_IPC_OUTBOUND,		// IPC outbound
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_IPC_INBOUND = VIDYO_CLIENT_PORTAL_FEATURE_NAME_IPC_INBOUND,		// IPC inbound
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_MEDERATOR_URL = VIDYO_CLIENT_PORTAL_FEATURE_NAME_MEDERATOR_URL,	// Moderator URL
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_TLS_TUNNELING = VIDYO_CLIENT_PORTAL_FEATURE_NAME_TLS_TUNNELING,	// TLS Tunneling
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_LOGIN_BANNER = VIDYO_CLIENT_PORTAL_FEATURE_NAME_LOGIN_BANNER,		// Login Banner
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_WELCOME_BANNER = VIDYO_CLIENT_PORTAL_FEATURE_NAME_WELCOME_BANNER,	// Welcome banner
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_PRIVATE_CHAT = VIDYO_CLIENT_PORTAL_FEATURE_NAME_PRIVATE_CHAT,		// Private chat
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_GROUP_CHAT = VIDYO_CLIENT_PORTAL_FEATURE_NAME_GROUP_CHAT,			// Group chat
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_CDR_VERSION_2_1 = VIDYO_CLIENT_PORTAL_FEATURE_NAME_CDR_VERSION_2_1,// Support for CDR version 2.1
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_ENDPOINT_DETAILS = VIDYO_CLIENT_PORTAL_FEATURE_NAME_ENDPOINT_DETAILS,// Support for Endpoint details and features
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_16_TILES = VIDYO_CLIENT_PORTAL_FEATURE_NAME_16_TILES,				// Support for 16 tiles
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_HTML_CHANGE_PASSWORD = VIDYO_CLIENT_PORTAL_FEATURE_NAME_HTML_CHANGE_PASSWORD,	// Support for HTML change password
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_ROUTER_PARTICIPANT_INFORMATION = VIDYO_CLIENT_PORTAL_FEATURE_NAME_ROUTER_PARTICIPANT_INFORMATION,	// Support for router participant information
	VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_FEATURE_NAME_MAX = VIDYO_CLIENT_PORTAL_FEATURE_NAME_MAX,					     // None - invalid
} VidyoClientPrivateSoapPortalFeaturesNames;

typedef enum VidyoClientPrivateSoapResultCode_
{
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_FAILURE 							= VIDYO_CLIENT_ERROR_SOAP_FAILURE,					// Result is some unknown general failure
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_SUCCESS 							= VIDYO_CLIENT_ERROR_SOAP_SUCCESS,					// Result is success
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_NOT_LICENSED 						= VIDYO_CLIENT_ERROR_SOAP_NOT_LICENSED,				// Not licensed
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_SEAT_LICENSE_EXPIRED 				= VIDYO_CLIENT_ERROR_SOAP_SEAT_LICENSE_EXPIRED,		// Seat license expired
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_WRONG_PIN 							= VIDYO_CLIENT_ERROR_SOAP_WRONG_PIN,				// Wrong PIN
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_CONFERENCE_LOCKED 					= VIDYO_CLIENT_ERROR_SOAP_CONFERENCE_LOCKED,		// Conference locked
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_ROOM_DISABLED 						= VIDYO_CLIENT_ERROR_SOAP_ROOM_DISABLED,			// Room disabled
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_GENERAL_FAULT 						= VIDYO_CLIENT_ERROR_SOAP_GENERAL_FAULT,			// General Fault
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_INVALID_ARGUMENT_FAULT 			= VIDYO_CLIENT_ERROR_SOAP_INVALID_ARGUMENT_FAULT,	// Invalid argument fault
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_MEMBER_NOT_ONLINE 					= VIDYO_CLIENT_ERROR_SOAP_MEMBER_NOT_ONLINE,		// Status of member is not online
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_NOT_OWNER_OF_ROOM 					= VIDYO_CLIENT_ERROR_SOAP_NOT_OWNER_OF_ROOM,		// Not owner of room
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_USER_NOT_FOUND 					= VIDYO_CLIENT_ERROR_SOAP_USER_NOT_FOUND,			// Specified user is not found
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_UNEXPECTED_SUBELEMENT_IN_MESSAGE 	= VIDYO_CLIENT_ERROR_SOAP_UNEXPECTED_SUBELEMENT_IN_MESSAGE,  	// Unexpected subelement in SOAP message
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_END_POINT_NOT_FOUND 				= VIDYO_CLIENT_ERROR_SOAP_END_POINT_NOT_FOUND,		// Endpoint not found
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_FAILED_PLACE_DIRECT_CALL 			= VIDYO_CLIENT_ERROR_SOAP_FAILED_PLACE_DIRECT_CALL,
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_IPC_JOIN_FAILURE 					= VIDYO_CLIENT_ERROR_SOAP_IPC_JOIN_FAILURE,			// Failure to join room on other portal
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_ALL_LINES_IN_USE 					= VIDYO_CLIENT_ERROR_SOAP_ALL_LINES_IN_USE,			// All lines are in use
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_RESOURCE_NOT_AVAILABLE 			= VIDYO_CLIENT_ERROR_SOAP_RESOURCE_NOT_AVAILABLE,	// Resource Not available
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_ACCESS_RESTRICTED 					= VIDYO_CLIENT_ERROR_SOAP_RESULT_ACCESS_RESTRICTED,	// Access restricted
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_USER_NOT_BOUND 					= VIDYO_CLIENT_ERROR_SOAP_RESULT_USER_NOT_BOUND,	// User is no bound
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_ROOM_IS_FULL						= VIDYO_CLIENT_ERROR_SOAP_ROOM_IS_FULL,				// Room is full
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_PORTAL_PREFIX_NOT_CONFIGURED		= VIDYO_CLIENT_ERROR_SOAP_PORTAL_PREFIX_NOT_CONFIGURED,	// Portal prefix is not configured
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_CONTROL_MEETING_FAILED				= VIDYO_CLIENT_ERROR_SOAP_CONTROL_MEETING_FAILED,	// Control meeting failed
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_SERVICE_NOT_IMPLEMENTED			= VIDYO_CLIENT_ERROR_HTTP_500_SERVER_ERROR,			// Requested service not implemented
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_INVALID_EXTENSION					= VIDYO_CLIENT_ERROR_INVALID_EXTENSION,				// Invalid extension
	VIDYO_CLIENT_PRIVATE_SOAP_RESULT_INVALID_ROOM						= VIDYO_CLIENT_ERROR_INVALID_ROOM,					// Invalid room
} VidyoClientPrivateSoapResultCode;


typedef VidyoClientPortalServiceEntityType VidyoClientPrivateSoapEntityType;
#define VIDYO_CLIENT_PRIVATE_SOAP_ENTITY_TYPE_MEMBER VIDYO_CLIENT_ENTITY_TYPE_MEMBER
#define VIDYO_CLIENT_PRIVATE_SOAP_ENTITY_TYPE_ROOM VIDYO_CLIENT_ENTITY_TYPE_ROOM
#define VIDYO_CLIENT_PRIVATE_SOAP_ENTITY_TYPE_LEGACY VIDYO_CLIENT_ENTITY_TYPE_LEGACY
#define VIDYO_CLIENT_PRIVATE_SOAP_ENTITY_TYPE_IPC_ROOM VIDYO_CLIENT_ENTITY_TYPE_IPC_ROOM
#define VIDYO_CLIENT_PRIVATE_SOAP_ENTITY_TYPE_SCHEDULED VIDYO_CLIENT_ENTITY_TYPE_SCHEDULED
#define VIDYO_CLIENT_PRIVATE_SOAP_ENTITY_TYPE_ANY VIDYO_CLIENT_ENTITY_TYPE_ANY


typedef VidyoClientMemberStatus VidyoClientPrivateSoapMemberStatus;
#define VIDYO_CLIENT_PRIVATE_SOAP_MEMBER_STATUS_ONLINE VIDYO_CLIENT_MEMBER_STATUS_ONLINE
#define VIDYO_CLIENT_PRIVATE_SOAP_MEMBER_STATUS_OFFLINE VIDYO_CLIENT_MEMBER_STATUS_OFFLINE
#define VIDYO_CLIENT_PRIVATE_SOAP_MEMBER_STATUS_BUSY VIDYO_CLIENT_MEMBER_STATUS_BUSY
#define VIDYO_CLIENT_PRIVATE_SOAP_MEMBER_STATUS_BUSY_IN_OWN_ROOM VIDYO_CLIENT_MEMBER_STATUS_BUSY_IN_OWN_ROOM
#define VIDYO_CLIENT_PRIVATE_SOAP_MEMBER_STATUS_RINGING VIDYO_CLIENT_MEMBER_STATUS_RINGING
#define VIDYO_CLIENT_PRIVATE_SOAP_MEMBER_STATUS_RING_ACCEPTED VIDYO_CLIENT_MEMBER_STATUS_RING_ACCEPTED
#define VIDYO_CLIENT_PRIVATE_SOAP_MEMBER_STATUS_RING_REJECTED VIDYO_CLIENT_MEMBER_STATUS_RING_REJECTED
#define VIDYO_CLIENT_PRIVATE_SOAP_MEMBER_STATUS_RING_NO_ANSWER VIDYO_CLIENT_MEMBER_STATUS_RING_NO_ANSWER
#define VIDYO_CLIENT_PRIVATE_SOAP_MEMBER_STATUS_ALERTING VIDYO_CLIENT_MEMBER_STATUS_ALERTING
#define VIDYO_CLIENT_PRIVATE_SOAP_MEMBER_STATUS_ALERT_CANCELLED VIDYO_CLIENT_MEMBER_STATUS_ALERT_CANCELLED

typedef VidyoClientMemberMode VidyoClientPrivateSoapMemberMode;
#define VIDYO_CLIENT_PRIVATE_SOAP_MEMBER_MODE_AVAILABLE VIDYO_CLIENT_MEMBER_MODE_AVAILABLE
#define VIDYO_CLIENT_PRIVATE_SOAP_MEMBER_MODE_AWAY VIDYO_CLIENT_MEMBER_MODE_AWAY
#define VIDYO_CLIENT_PRIVATE_SOAP_MEMBER_MODE_DONOTDISTURB VIDYO_CLIENT_MEMBER_MODE_DONOTDISTURB

typedef VidyoClientRoomStatus VidyoClientPrivateSoapRoomStatus;
#define VIDYO_CLIENT_PRIVATE_SOAP_ROOM_EMPTY VIDYO_CLIENT_ROOM_EMPTY
#define VIDYO_CLIENT_PRIVATE_SOAP_ROOM_FULL VIDYO_CLIENT_ROOM_FULL
#define VIDYO_CLIENT_PRIVATE_SOAP_ROOM_OCCUPIED VIDYO_CLIENT_ROOM_OCCUPIED

typedef VidyoClientRoomMode VidyoClientPrivateSoapRoomMode;


typedef VidyoClientAccountData VidyoClientPrivateSoapAccountData;

typedef struct VidyoClientPrivateSoapConferenceParticipantData_
{
	VidyoClientPrivateSoapAccountData account;
	char uri[MAX_URI_LEN];
	VidyoBool isGuestParticipant;		// Is this user joined as guest in this conference?
} VidyoClientPrivateSoapConferenceParticipantData;

typedef struct VidyoClientPrivateSoapInEventJoinConference_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.
	// entityID or extension should be provided. If both are given only entityID will be used.
	char entityID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID - Unique
	char extension[VIDYO_CLIENT_PRIVATE_SOAP_EXTENSION_SIZE]; // Extension number
	char roomPIN[VIDYO_CLIENT_PRIVATE_SOAP_PIN_SIZE];	// Room PIN - If room has PIN
	char referenceNumber[VIDYO_CLIENT_REFERENCE_NUMBER_LEN]; /* Reference number - optional */
	/*! Join the conference with camera muted */
	VidyoBool muteCamera;
	/*! Join the conference with microphone muted */
	VidyoBool muteMicrophone;
	/*! Join the conference with speaker muted */
	VidyoBool muteSpeaker;
} VidyoClientPrivateSoapInEventJoinConference;

typedef struct VidyoClientPrivateSoapOutEventJoinConference_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of join conference request
	VidyoClientPrivateSoapFault fault;
} VidyoClientPrivateSoapOutEventJoinConference;

typedef struct VidyoClientPrivateSoapInEventJoinIpcConference_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char localPart[VIDYO_MAX_PATH];
	char domain[VIDYO_MAX_PATH];
	char roomPIN[VIDYO_CLIENT_PRIVATE_SOAP_PIN_SIZE];	// Room PIN - If room has PIN
	char referenceNumber[VIDYO_CLIENT_REFERENCE_NUMBER_LEN]; /* Reference number - optional */
	/*! Join the conference with camera muted */
	VidyoBool muteCamera;
	/*! Join the conference with microphone muted */
	VidyoBool muteMicrophone;
	/*! Join the conference with speaker muted */
	VidyoBool muteSpeaker;
}VidyoClientPrivateSoapInEventJoinIpcConference;

typedef struct VidyoClientPrivateSoapOutEventJoinIpcConference_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of join conference request
	VidyoClientPrivateSoapFault fault;
} VidyoClientPrivateSoapOutEventJoinIpcConference;

typedef struct VidyoClientPrivateSoapInEventJoinConferenceByName_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char userName[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE];	// Display Name of user
	char roomPIN[VIDYO_CLIENT_PRIVATE_SOAP_PIN_SIZE];		// Room PIN - If room has PIN
	char referenceNumber[VIDYO_CLIENT_REFERENCE_NUMBER_LEN]; /* Reference number - optional */
	/*! Join the conference with camera muted */
	VidyoBool muteCamera;
	/*! Join the conference with microphone muted */
	VidyoBool muteMicrophone;
	/*! Join the conference with speaker muted */
	VidyoBool muteSpeaker;
} VidyoClientPrivateSoapInEventJoinConferenceByName;

typedef struct VidyoClientPrivateSoapOutEventJoinConferenceByName_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of join conference request
} VidyoClientPrivateSoapOutEventJoinConferenceByName;

typedef struct VidyoClientPrivateSoapInEventStartMyConference_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.
	char referenceNumber[VIDYO_CLIENT_REFERENCE_NUMBER_LEN]; /* Reference number - optional */
	/*! Join the conference with camera muted */
	VidyoBool muteCamera;
	/*! Join the conference with microphone muted */
	VidyoBool muteMicrophone;
	/*! Join the conference with speaker muted */
	VidyoBool muteSpeaker;
} VidyoClientPrivateSoapInEventStartMyConference;


typedef struct VidyoClientPrivateSoapOutEventStartMyConference_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of start my conference request
} VidyoClientPrivateSoapOutEventStartMyConference;

typedef struct VidyoClientPrivateSoapInEventLoginRequest_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char portalUri[VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_URI_SIZE];
	char userName[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE];
	char userPass[VIDYO_CLIENT_PRIVATE_SOAP_PASSWORD_SIZE];
	VidyoClientPrivateSoapClientType clientType;
} VidyoClientPrivateSoapInEventLoginRequest;

typedef struct VidyoClientPrivateSoapOutEventLoginRequest_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	
	char portalUri[VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_URI_SIZE];
	char userName[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE];
	char PortalAccessKey[VIDYO_CLIENT_PRIVATE_SOAP_PAK_SIZE];
	char serverAddress[VIDYO_CLIENT_PRIVATE_SOAP_HOSTNAME_SIZE];
	char proxyAddress[VIDYO_CLIENT_PRIVATE_SOAP_HOSTNAME_SIZE];
	char vmIdentity[VIDYO_CLIENT_PRIVATE_SOAP_VIDYO_MANAGER_ID_SIZE];
	char locationTag[VIDYO_CLIENT_PRIVATE_SOAP_ENDPOINT_LOCATION_TAG_SIZE];
	VidyoClientProxyType proxyType;
	char reverseProxyAddress[VIDYO_CLIENT_PRIVATE_SOAP_HOSTNAME_SIZE]; 
	char clientExternalIPAddress[MAX_IPADDRESS_LEN]; 					
} VidyoClientPrivateSoapOutEventLoginRequest;

typedef struct VidyoClientPrivateOutEventPromptGuestLink_
{
	VidyoBool hasPin;
	char portalUri[VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_URI_SIZE];
	char roomKey[VIDYO_CLIENT_PRIVATE_SOAP_ROOMKEY_SIZE];
} VidyoClientPrivateOutEventPromptGuestLink;

typedef struct VidyoClientPrivateSoapInEventLinkEndpoint_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char LongEID[VIDYO_CLIENT_PRIVATE_SOAP_LONG_EID_SIZE];
	char applicationName[VIDYO_CLIENT_APPLICATION_NAME_LEN];
	char applicationVersion[VIDYO_CLIENT_VERSION_SIZE];
	char applicationOs[VIDYO_CLIENT_PLATFORM_OS_NAME_LEN];
	char deviceModel[VIDYO_CLIENT_DEVICE_MODEL_LEN];
} VidyoClientPrivateSoapInEventLinkEndpoint;

typedef struct VidyoClientPrivateSoapOutEventLinkEndpoint_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;
	VidyoClientPrivateSoapAccountData accountData;
} VidyoClientPrivateSoapOutEventLinkEndpoint;

typedef struct VidyoClientPrivateSoapInEventGuestLink_
{
	VidyoUint typeRequest;
	VidyoUint requestId;
	VidyoClientClientType clientType;

	char portalUri[VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_URI_SIZE];
	char roomKey[VIDYO_CLIENT_PRIVATE_SOAP_ROOMKEY_SIZE];
	char guestName[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE];
	char pin[VIDYO_CLIENT_PRIVATE_SOAP_PIN_SIZE];
	char referenceNumber[VIDYO_CLIENT_REFERENCE_NUMBER_LEN]; /* Reference number - optional */
	/*! Join the conference with camera muted */
	VidyoBool muteCamera;
	/*! Join the conference with microphone muted */
	VidyoBool muteMicrophone;
	/*! Join the conference with speaker muted */
	VidyoBool muteSpeaker;
} VidyoClientPrivateSoapInEventGuestLink;

typedef struct VidyoClientPrivateSoapOutEventGuestLink_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;

	VidyoUint guestID;
	VidyoBool isLocked;
	VidyoBool hasPin;
	char vmaddress[VIDYO_MAX_PATH];
	char proxyaddress[VIDYO_CLIENT_PRIVATE_SOAP_HOSTNAME_SIZE];
	char loctag[VIDYO_CLIENT_PRIVATE_SOAP_ENDPOINT_LOCATION_TAG_SIZE];
	char un[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE];
	char pak[VIDYO_CLIENT_PRIVATE_SOAP_PAK_SIZE];
	char portal[VIDYO_CLIENT_PRIVATE_SOAP_HOSTNAME_SIZE];
	char portalVersion[VIDYO_CLIENT_PRIVATE_SOAP_PORTALVERSION_SIZE];
	VidyoClientProxyType proxyType;
	char reverseProxyAddress[VIDYO_CLIENT_PRIVATE_SOAP_HOSTNAME_SIZE]; 
	char clientExternalIPAddress[MAX_IPADDRESS_LEN]; 					

	VidyoClientPrivateSoapResultCode result;
	VidyoClientPrivateSoapFault fault;
} VidyoClientPrivateSoapOutEventGuestLink;

typedef struct VidyoClientPrivateSoapInEventJoinWithRoomKey_
{
	VidyoUint typeRequest;
	VidyoUint requestId;
	VidyoClientClientType clientType;

	char portalUri[VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_URI_SIZE];
	char roomKey[VIDYO_CLIENT_PRIVATE_SOAP_ROOMKEY_SIZE];
	char pin[VIDYO_CLIENT_PRIVATE_SOAP_PIN_SIZE];
	char referenceNumber[VIDYO_CLIENT_REFERENCE_NUMBER_LEN]; /* Reference number - optional */
	/*! Join the conference with camera muted */
	VidyoBool muteCamera;
	/*! Join the conference with microphone muted */
	VidyoBool muteMicrophone;
	/*! Join the conference with speaker muted */
	VidyoBool muteSpeaker;
} VidyoClientPrivateSoapInEventJoinWithRoomKey;

typedef struct VidyoClientPrivateSoapOutEventJoinWithRoomKey_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;

	VidyoClientPrivateSoapResultCode result;
	VidyoClientPrivateSoapFault fault;
} VidyoClientPrivateSoapOutEventJoinWithRoomKey;

typedef struct VidyoClientPrivateSoapInEventGuestClientVersionOnServer_
{
	VidyoUint typeRequest;
	VidyoUint requestId;

	char portalUri[VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_URI_SIZE];
	VidyoClientClientType clientType;
	VidyoBool userInitiated;
} VidyoClientPrivateSoapInEventClientVersionOnServer;

typedef struct VidyoClientPrivateSoapOutEventGuestClientVersionOnServer_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;

	VidyoBool userInitiated;
	char currentTag[VIDYO_CLIENT_PRIVATE_SOAP_CURRENT_TAG_SIZE];
	char installerUri[VIDYO_CLIENT_PRIVATE_SOAP_INSTALLER_URI_SIZE];
} VidyoClientPrivateSoapOutEventGuestClientVersionOnServer;


typedef VidyoClientPortalServiceSearchBy VidyoClientPrivateSoapSearchBy;
#define VIDYO_CLIENT_PRIVATE_SOAP_SEARCH_BY_DISPLAY_NAME VIDYO_CLIENT_SEARCH_BY_DISPLAY_NAME
#define VIDYO_CLIENT_PRIVATE_SOAP_SEARCH_BY_EXTENSION_NUM VIDYO_CLIENT_SEARCH_BY_EXTENSION_NUM

typedef VidyoClientPortalServiceSortOrder VidyoClientPrivateSoapSortOrder;
#define VIDYO_CLIENT_PRIVATE_SOAP_SORT_ORDER_ASCENDING VIDYO_CLIENT_SORT_ORDER_ASCENDING
#define VIDYO_CLIENT_PRIVATE_SOAP_SORT_ORDER_DESCENDING VIDYO_CLIENT_SORT_ORDER_DESCENDING 

typedef VidyoClientPortalServiceSearchRequest VidyoClientPrivateSoapInEventSearchRequest;
typedef VidyoClientOutEventPortalServiceSearch VidyoClientPrivateSoapOutEventSearch;

typedef VidyoClientPortalServiceDirectCall VidyoClientPrivateSoapInEventDirectCall;

typedef struct VidyoClientPrivateSoapOutEventDirectCall_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of DirectCall request. 
									// Wrong PIN and conference locked are not valid for direct call response
} VidyoClientPrivateSoapOutEventDirectCall;

typedef struct VidyoClientPrivateSoapInEventDirectCallByName_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char userName[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE];	// Display Name of user
	// String invite has to be added
	/*! Join the conference with camera muted */
	VidyoBool muteCamera;
	/*! Join the conference with microphone muted */
	VidyoBool muteMicrophone;
	/*! Join the conference with speaker muted */
	VidyoBool muteSpeaker;
} VidyoClientPrivateSoapInEventDirectCallByName;

typedef struct VidyoClientPrivateSoapOutEventDirectCallByName_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of DirectCall request. 
									// Wrong PIN and conference locked are not valid for direct call response
} VidyoClientPrivateSoapOutEventDirectCallByName;

typedef struct VidyoClientPrivateSoapInEventSearchMyContacts_
{
	VidyoUint typeRequest;
	VidyoUint requestId;// A unique request ID to match the response (out event). This is optional.

	VidyoUint start;	// Starting number - First request can start with 0 as value
	VidyoUint limit;	// Limit in number of response - MAX can be VIDYO_CLIENT_PRIVATE_SOAP_SEARCH_SIZE
	VidyoClientPrivateSoapSearchBy searchBy;
	VidyoClientPrivateSoapSortOrder sortOrder;
	char searchString[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE]; // Search string
} VidyoClientPrivateSoapInEventSearchMyContacts;

// Response to VidyoClientPrivateSoapInEventSearchMyContacts is VidyoClientPrivateSoapOutEventSearch

typedef struct VidyoClientPrivateSoapInEventMyAccount_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

} VidyoClientPrivateSoapInEventMyAccount;

typedef struct VidyoClientPrivateSoapOutEventMyAccount_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of my account request
    VidyoClientPrivateSoapAccountData accountData;
} VidyoClientPrivateSoapOutEventMyAccount;

typedef struct VidyoClientPrivateSoapInEventAddToMyContacts_
{
	VidyoUint typeRequest;
	VidyoUint requestId;								// A unique request ID to match the response (out event) - optional field.

	char entityID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID - Unique
} VidyoClientPrivateSoapInEventAddToMyContacts;

typedef struct VidyoClientPrivateSoapOutEventAddToMyContacts_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of add to my contact request
} VidyoClientPrivateSoapOutEventAddToMyContacts;


typedef struct VidyoClientPrivateSoapInEventRemoveFromMyContacts_
{
	VidyoUint typeRequest;
	VidyoUint requestId;								// A unique request ID to match the response (out event) - optional field.

	char entityID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID - Unique
} VidyoClientPrivateSoapInEventRemoveFromMyContacts;

typedef struct VidyoClientPrivateSoapOutEventRemoveFromMyContacts_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of remove from my contact request
} VidyoClientPrivateSoapOutEventRemoveFromMyContacts;


typedef struct VidyoClientPrivateSoapInEventSearchByEntityId_
{
	VidyoUint typeRequest;
	VidyoUint requestId;	// A unique request ID to match the response (out event). This is optional.

	char entityID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID to be used for searching.
	VidyoBool filterValid;	// Validity of filter information - If set to LMI_TRUE all the following fields
							// used as search filter should be valid. If set to LMI_FALSE all the following
							// fields used as search filter are ignored. Filter information is ignored means
							// whole data from Portal are retrieved.
	VidyoUint start;	// Starting number - First request can start with 0 as value
	VidyoUint limit;	// Limit in number of response - MAX can be VIDYO_CLIENT_PRIVATE_SOAP_SEARCH_SIZE
	VidyoClientPrivateSoapSearchBy searchBy;
	VidyoClientPrivateSoapSortOrder sortOrder;
	char searchString[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE]; // Search string
} VidyoClientPrivateSoapInEventSearchByEntityId;

// Response to VidyoClientPrivateSoapInEventSearchByMyEntityId is VidyoClientPrivateSoapOutEventSearch
typedef struct VidyoClientPrivateSoapInEventSearchByMyEntityId_
{
	VidyoUint typeRequest;
	VidyoUint requestId;	// A unique request ID to match the response (out event). This is optional.

	VidyoBool filterValid;	// Validity of filter information - If set to LMI_TRUE all the following fields
							// used as search filter should be valid. If set to LMI_FALSE all the following
							// fields used as search filter are ignored. Filter information is ignored means
							// whole data from Portal are retrieved.
	VidyoUint start;	// Starting number - First request can start with 0 as value
	VidyoUint limit;	// Limit in number of response - MAX can be VIDYO_CLIENT_PRIVATE_SOAP_SEARCH_SIZE
	VidyoClientPrivateSoapSearchBy searchBy;
	VidyoClientPrivateSoapSortOrder sortOrder;
	char searchString[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE]; // Search string
} VidyoClientPrivateSoapInEventSearchByMyEntityId;


// Response to VidyoClientPrivateSoapInEventGetEntityByEntityId is VidyoClientPrivateSoapOutEventSearch
typedef struct VidyoClientPrivateSoapInEventGetEntityByEntityId_
{
	VidyoUint typeRequest;
	VidyoUint requestId;	// A unique request ID to match the response (out event). This is optional.

	char entityID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID to be used for searching.
} VidyoClientPrivateSoapInEventGetEntityByEntityId;

// Response to VidyoClientPrivateSoapInEventSearchByEntityId is VidyoClientPrivateSoapOutEventSearch
typedef struct VidyoClientPrivateSoapInEventInviteToConference_
{
	VidyoUint typeRequest;
	VidyoUint requestId;									// A unique request ID to match the response (out event).

	VidyoClientPortalServiceEntityType entityType;			// Entity Type - Only valid values are Member or Legacy
															// If this value is Member, entityID should be filled
															// If this value is Legacy, legacyID should be filled
	char conferenceID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the room to where Invite to Conference is being requested
	char entityID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];		// Entity ID of the participant who is invited to conference
	char legacyID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];		// ID of the legacy participant who is invited to conference
															// This is the value of field extension in VidyoClientPrivateSoapAccountData
															// when the legacy endpoint's informtion is taken from Search result.
} VidyoClientPrivateSoapInEventInviteToConference;

typedef struct VidyoClientPrivateSoapOutEventInviteToConference_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of InviteToConference request. 
} VidyoClientPrivateSoapOutEventInviteToConference;

typedef struct VidyoClientPrivateSoapInEventDropParticipant_
{
	VidyoUint typeRequest;
	VidyoUint requestId;									// A unique request ID to match the response (out event).

	char conferenceID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the conference room from where participant has to be disconnected
	char participantID[VIDYO_CLIENT_PRIVATE_SOAP_PARTICIPANTID_SIZE];	// Participant ID of the participant who have to be disconnected from conference
} VidyoClientPrivateSoapInEventDropParticipant;

typedef struct VidyoClientPrivateSoapOutEventDropParticipant_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of LeaveConference request. 
} VidyoClientPrivateSoapOutEventDropParticipant;

typedef struct VidyoClientPrivateSoapInEventGetParticipants_
{
	VidyoUint typeRequest;
	VidyoUint requestId;// A unique request ID to match the response (out event). This is optional.

	char conferenceID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Conference ID - Entity ID of room used for conference
	VidyoUint start;	// Starting number - First request can start with 0 as value
	VidyoUint limit;	// Limit in number of response - MAX can be VIDYO_CLIENT_PRIVATE_SOAP_SEARCH_SIZE
	VidyoClientPrivateSoapSearchBy searchBy;
	VidyoClientPrivateSoapSortOrder sortOrder;
	char searchString[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE]; // Search string
} VidyoClientPrivateSoapInEventGetParticipants;

typedef struct VidyoClientPrivateSoapOutEventGetParticipants_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoUint total;				// Total number of users matching the given search criteria
	VidyoUint start;				// Starting number specified in request
	VidyoClientPrivateSoapResultCode result;	// Result of get participants request
	VidyoUint numEntries;			// Number of entries in this response
    VidyoClientPrivateSoapConferenceParticipantData participantData[VIDYO_CLIENT_PRIVATE_SOAP_SEARCH_SIZE];
} VidyoClientPrivateSoapOutEventGetParticipants;

typedef struct VidyoClientPrivateSoapOutEventGetParticipantsEx_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoUint total;				// Total number of users matching the given search criteria
	VidyoUint start;				// Starting number specified in request
	VidyoClientPrivateSoapResultCode result;	// Result of get participants request
	VidyoUint numEntries;			// Number of entries in this response
    VidyoClientPrivateSoapConferenceParticipantData participantData[VIDYO_CLIENT_PRIVATE_SOAP_SEARCH_SIZE];
} VidyoClientPrivateSoapOutEventGetParticipantsEx;

typedef struct VidyoClientPrivateSoapInEventCreateRoom_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char name[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE];	// Name of room to be created
	char extension[VIDYO_CLIENT_PRIVATE_SOAP_EXTENSION_SIZE];// Extension number
} VidyoClientPrivateSoapInEventCreateRoom;

typedef struct VidyoClientPrivateSoapOutEventCreateRoom_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of create room request
    VidyoClientPrivateSoapAccountData accountData;
} VidyoClientPrivateSoapOutEventCreateRoom;

typedef struct VidyoClientPrivateSoapInEventDeleteRoom_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Room ID
} VidyoClientPrivateSoapInEventDeleteRoom;

typedef struct VidyoClientPrivateSoapOutEventDeleteRoom_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of delete room request
} VidyoClientPrivateSoapOutEventDeleteRoom;

typedef struct VidyoClientPrivateSoapInEventCreateRoomPin_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Room ID - Unique
	char roomPIN[VIDYO_CLIENT_PRIVATE_SOAP_PIN_SIZE];	// Room PIN to be used
} VidyoClientPrivateSoapInEventCreateRoomPin;

typedef struct VidyoClientPrivateSoapOutEventCreateRoomPin_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of create room pin request
} VidyoClientPrivateSoapOutEventCreateRoomPin;

typedef struct VidyoClientPrivateSoapInEventRemoveRoomPin_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Room ID - Unique
} VidyoClientPrivateSoapInEventRemoveRoomPin;

typedef struct VidyoClientPrivateSoapOutEventRemoveRoomPin_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of remove room pin request
} VidyoClientPrivateSoapOutEventRemoveRoomPin;

typedef struct VidyoClientPrivateSoapInEventLockRoom_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Room ID - Unique
	char moderatorPin[PIN_SIZE];						// Optional moderator pin
} VidyoClientPrivateSoapInEventLockRoom;

typedef struct VidyoClientPrivateSoapOutEventLockRoom_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;		// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientError result;	// Result of lock room request
} VidyoClientPrivateSoapOutEventLockRoom;

typedef struct VidyoClientPrivateSoapInEventUnlockRoom_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Room ID - Unique
	char moderatorPin[PIN_SIZE];						// Optional moderator pin
} VidyoClientPrivateSoapInEventUnlockRoom;

typedef struct VidyoClientPrivateSoapOutEventUnlockRoom_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;		// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientError result;	// Result of Unlock room request
} VidyoClientPrivateSoapOutEventUnlockRoom;

typedef struct VidyoClientPrivateSoapInEventLogOut_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

} VidyoClientPrivateSoapInEventLogOut;

typedef struct VidyoClientPrivateSoapOutEventLogOut_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of logout request
} VidyoClientPrivateSoapOutEventLogOut;

typedef struct VidyoClientPrivateSoapInEventMuteAudio_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char conferenceID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the conference 
	char participantID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];		// Entity ID of the participant who is to be muted
} VidyoClientPrivateSoapInEventMuteAudio;

typedef struct VidyoClientPrivateSoapOutEventMuteAudio_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of mute audio request
} VidyoClientPrivateSoapOutEventMuteAudio;

typedef struct VidyoClientPrivateSoapInEventUnmuteAudio_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char conferenceID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the conference 
	char participantID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];		// Entity ID of the participant who is to be unmuted
} VidyoClientPrivateSoapInEventUnmuteAudio;

typedef struct VidyoClientPrivateSoapOutEventUnmuteAudio_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of unmute audio request
} VidyoClientPrivateSoapOutEventUnmuteAudio;

typedef struct VidyoClientPrivateSoapInEventStartVideo_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char conferenceID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the conference 
	char participantID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];		// Entity ID of the participant whose video is to be shown
} VidyoClientPrivateSoapInEventStartVideo;

typedef struct VidyoClientPrivateSoapOutEventStartVideo_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of start video request
} VidyoClientPrivateSoapOutEventStartVideo;

typedef struct VidyoClientPrivateSoapInEventStopVideo_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char conferenceID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the conference 
	char participantID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];		// Entity ID of the participant whose video is to be hidden
} VidyoClientPrivateSoapInEventStopVideo;

typedef struct VidyoClientPrivateSoapOutEventStopVideo_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of mute stop video
} VidyoClientPrivateSoapOutEventStopVideo;


typedef struct VidyoClientPrivateSoapInEventGetUserName_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

} VidyoClientPrivateSoapInEventGetUserName;

typedef struct VidyoClientPrivateSoapOutEventGetUserName_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of logout request
	char realUserName[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE]; // Case sensitive user name as entered in portal DB.
} VidyoClientPrivateSoapOutEventGetUserName;

typedef struct VidyoClientPrivateSoapInEventCreateWebcastUrl_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the room 
} VidyoClientPrivateSoapInEventCreateWebcastUrl;

typedef struct VidyoClientPrivateSoapOutEventCreateWebcastUrl_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of Create Webcast url
} VidyoClientPrivateSoapOutEventCreateWebcastUrl;

typedef struct VidyoClientPrivateSoapInEventRemoveWebcastUrl_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the room 
} VidyoClientPrivateSoapInEventRemoveWebcastUrl;

typedef struct VidyoClientPrivateSoapOutEventRemoveWebcastUrl_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of Remove Webcast url
} VidyoClientPrivateSoapOutEventRemoveWebcastUrl;

typedef struct VidyoClientPrivateSoapInEventGetWebcastUrl_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the room 
} VidyoClientPrivateSoapInEventGetWebcastUrl;

typedef struct VidyoClientPrivateSoapOutEventGetWebcastUrl_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of GetWebcastUrl
	char webcastURL[VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_URI_SIZE];						// Web cast URL
	VidyoBool hasPin;								// hasPin : True if webcast is pin enabled; False otherwise 
} VidyoClientPrivateSoapOutEventGetWebcastUrl;

typedef struct VidyoClientPrivateSoapInEventCreateWebcastPin_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the room 
	char pin[VIDYO_CLIENT_PRIVATE_SOAP_PIN_SIZE];	// Pin of the Webcast 
} VidyoClientPrivateSoapInEventCreateWebcastPin;

typedef struct VidyoClientPrivateSoapOutEventCreateWebcastPin_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of Create Webcast pin
} VidyoClientPrivateSoapOutEventCreateWebcastPin;

typedef struct VidyoClientPrivateSoapInEventRemoveWebcastPin_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the room 
} VidyoClientPrivateSoapInEventRemoveWebcastPin;

typedef struct VidyoClientPrivateSoapOutEventRemoveWebcastPin_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of Remove Webcast pin
} VidyoClientPrivateSoapOutEventRemoveWebcastPin;

typedef struct VidyoClientPrivateSoapInEventCreateModeratorPin_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the room 
	char pin[VIDYO_CLIENT_PRIVATE_SOAP_PIN_SIZE];	// Pin of the moderator 
} VidyoClientPrivateSoapInEventCreateModeratorPin;

typedef struct VidyoClientPrivateSoapOutEventCreateModeratorPin_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of Create Moderator pin
} VidyoClientPrivateSoapOutEventCreateModeratorPin;

typedef struct VidyoClientPrivateSoapInEventRemoveModeratorPin_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the room 
} VidyoClientPrivateSoapInEventRemoveModeratorPin;

typedef struct VidyoClientPrivateSoapOutEventRemoveModeratorPin_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of Remove moderator pin
} VidyoClientPrivateSoapOutEventRemoveModeratorPin;

typedef struct VidyoClientPrivateSoapInEventCreateScheduledRoom_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.
	VidyoBool setPIN;							// If room has to created with PIN set this to VIDYO_TRUE. Set to VIDYO_FALSE when no PIN required for the room.
} VidyoClientPrivateSoapInEventCreateScheduledRoom;

typedef struct VidyoClientPrivateSoapOutEventCreateScheduledRoom_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of Create Scheduled Room 
	char roomExtn[VIDYO_CLIENT_PRIVATE_SOAP_ROOMEXTN_SIZE]; // Extension of created scheduled room
	char roomPin[VIDYO_CLIENT_PRIVATE_SOAP_ROOMPIN_SIZE]; // pin of created scheduled room
	char invite[VIDYO_CLIENT_PRIVATE_SOAP_INVITECONTENT_SIZE]; // invite content for the created scheduled room
	char subject[VIDYO_CLIENT_PRIVATE_SOAP_INVITECONTENT_SIZE]; // invite subject for the created scheduled room
	char roomURL[VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_URI_SIZE]; // url of the created scheduled room

} VidyoClientPrivateSoapOutEventCreateScheduledRoom;

typedef struct VidyoClientPrivateSoapInEventGetInviteContent_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.
	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Optional Entity ID to specify created room; empty id (null string) will specify default room 

} VidyoClientPrivateSoapInEventGetInviteContent;

typedef struct VidyoClientPrivateSoapOutEventGetInviteContent_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

    VidyoClientPrivateSoapResultCode result;	// Result of Create Scheduled Room
	char invite[VIDYO_CLIENT_PRIVATE_SOAP_INVITECONTENT_SIZE]; // invite content for the room
	char subject[VIDYO_CLIENT_PRIVATE_SOAP_INVITECONTENT_SIZE]; // invite subject for the room
} VidyoClientPrivateSoapOutEventGetInviteContent;

typedef struct VidyoClientPrivateSoapInEventGetRoomAccessOptions_
{
    VidyoUint typeRequest;
    VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.
    char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Optional Entity ID to specify created room; empty id (null string) will specify default room

} VidyoClientPrivateSoapInEventGetRoomAccessOptions;

typedef struct VidyoClientPrivateSoapOutEventGetRoomAccessOptions_
{
    VidyoUint typeRequest;
    VidyoUint error;
    VidyoUint httpStatusCode;
    VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;
	VidyoUint accessOptionCount;
	char roomURL[MAX_URI_LEN];
	char extension[VIDYO_CLIENT_PRIVATE_SOAP_ROOMEXTN_SIZE];
	char pin[VIDYO_CLIENT_PRIVATE_SOAP_ROOMPIN_SIZE];
	char dialInNumber[VIDYO_CLIENT_PRIVATE_SOAP_ROOMDIALIN_SIZE];

} VidyoClientPrivateSoapOutEventGetRoomAccessOptions;

typedef struct VidyoClientPrivateSoapInEventGetConferenceID_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			

}VidyoClientPrivateSoapInEventGetConferenceID;

typedef struct VidyoClientPrivateSoapOutEventGetConferenceID_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of Get Conference ID
	char conferenceID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Conference ID
}VidyoClientPrivateSoapOutEventGetConferenceID;

typedef struct VidyoClientPrivateSoapInEventGenerateAuthToken_
{
	VidyoUint typeRequest;
	VidyoUint requestId;									// A unique request ID to match the response (out event) - should be copy of in event.
	VidyoInt validityTime;									// Validity time for the generated authentication token.
	char endpointID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Endpoint ID to generate authentication token specific to this endpoint. 

}VidyoClientPrivateSoapInEventGenerateAuthToken;

typedef struct VidyoClientPrivateSoapOutEventGenerateAuthToken_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of Generate Authentication Token
	char authToken[VIDYO_CLIENT_PRIVATE_SOAP_FIELD_SIZE];	// Authentication Token
}VidyoClientPrivateSoapOutEventGenerateAuthToken;

typedef struct VidyoClientPrivateSoapInEventGetPortalFeatures_
{
	VidyoUint typeRequest;
	VidyoUint requestId;									// A unique request ID to match the response (out event) - should be copy of in event.
}VidyoClientPrivateSoapInEventGetPortalFeatures;

typedef struct VidyoClientPrivateSoapPortalFeatures_
{
	VidyoClientPrivateSoapPortalFeaturesNames featureName;
	VidyoBool isEnabled;
}VidyoClientPrivateSoapPortalFeatures;

typedef struct VidyoClientPrivateSoapOutEventGetPortalFeatures_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of Generate Authentication Token
	VidyoUint featureCount;
	VidyoClientPrivateSoapPortalFeatures features[VIDYO_CLIENT_PRIVATE_SOAP_PORTALFEATURE_NUM];
}VidyoClientPrivateSoapOutEventGetPortalFeatures;

typedef struct VidyoClientPrivateSoapInEventGetPortalFeaturesAnonymous_
{
    VidyoUint typeRequest;
    VidyoUint requestId;									// A unique request ID to match the response (out event) - should be copy of in event.
    char portal[VIDYO_CLIENT_PRIVATE_SOAP_HOSTNAME_SIZE];
}VidyoClientPrivateSoapInEventGetPortalFeaturesAnonymous;

typedef struct VidyoClientPrivateSoapOutEventGetPortalFeaturesAnonymous_
{
    VidyoUint typeRequest;
    VidyoUint error;
    VidyoUint httpStatusCode;
    VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

    VidyoClientPrivateSoapResultCode result;	// Result of Generate Authentication Token
    VidyoUint featureCount;
    VidyoClientPrivateSoapPortalFeatures features[VIDYO_CLIENT_PRIVATE_SOAP_PORTALFEATURE_NUM];
}VidyoClientPrivateSoapOutEventGetPortalFeaturesAnonymous;


typedef struct VidyoClientPrivateSoapInEventCreateRoomUrl_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the room 
} VidyoClientPrivateSoapInEventCreateRoomUrl;

typedef struct VidyoClientPrivateSoapOutEventCreateRoomUrl_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of Create room url
} VidyoClientPrivateSoapOutEventCreateRoomUrl;

typedef struct VidyoClientPrivateSoapInEventRemoveRoomUrl_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the room 
} VidyoClientPrivateSoapInEventRemoveRoomUrl;

typedef struct VidyoClientPrivateSoapOutEventRemoveRoomUrl_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of Remove room url
} VidyoClientPrivateSoapOutEventRemoveRoomUrl;

typedef struct VidyoClientPrivateSoapInEventUpdatePassword_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

	char password[VIDYO_CLIENT_PRIVATE_SOAP_PASSWORD_SIZE];	// password of the user 
} VidyoClientPrivateSoapInEventUpdatePassword;

typedef struct VidyoClientPrivateSoapOutEventUpdatePassword_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of update password
} VidyoClientPrivateSoapOutEventUpdatePassword;

typedef struct VidyoClientPrivateSoapInEventGetEntityByRoomKey_
{
	VidyoUint typeRequest;
	VidyoUint requestId;

	char roomKey[VIDYO_CLIENT_PRIVATE_SOAP_ROOMKEY_SIZE];
} VidyoClientPrivateSoapInEventGetEntityByRoomKey;

typedef struct VidyoClientPrivateSoapOutEventGetEntityByRoomKey_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of GetEntityByRoomKey request
    VidyoClientPrivateSoapAccountData accountData;
} VidyoClientPrivateSoapOutEventGetEntityByRoomKey;

typedef struct VidyoClientPrivateSoapInEventLoginWelcomeBanner_
{
	VidyoUint typeRequest;
	VidyoUint requestId;
} VidyoClientPrivateSoapInEventLoginWelcomeBanner;

typedef struct VidyoClientPrivateSoapLoginHistory_
{
	char result[VIDYO_CLIENT_PRIVATE_SOAP_BANNER_COLUMN_SIZE];
	char ipAddress[VIDYO_CLIENT_PRIVATE_SOAP_BANNER_COLUMN_SIZE];
	char timeOfResult[VIDYO_CLIENT_PRIVATE_SOAP_BANNER_COLUMN_SIZE];
} VidyoClientPrivateSoapLoginHistory;



typedef struct VidyoClientPrivateSoapOutEventLoginWelcomeBanner_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the response (out event) - should be copy of in event.
	
	char loginBanner[VIDYO_CLIENT_PRIVATE_SOAP_BANNER_SIZE];
	char welcomeBanner[VIDYO_CLIENT_PRIVATE_SOAP_BANNER_SIZE];
	char passwordExpiration[VIDYO_CLIENT_PRIVATE_SOAP_BANNER_COLUMN_SIZE];
	VidyoUint numEntries;			// Number of entries in this response
	VidyoClientPrivateSoapResultCode result;	// Result of search request
    VidyoClientPrivateSoapLoginHistory loginHistory[VIDYO_CLIENT_PRIVATE_SOAP_LOGIN_HISTORY_SIZE];
} VidyoClientPrivateSoapOutEventLoginWelcomeBanner;


typedef struct VidyoClientPrivateSoapInEventGetModeratorURL_
{
	VidyoUint typeRequest;
	VidyoUint requestId;
	
	char roomID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];	// Entity ID of the room 
} VidyoClientPrivateSoapInEventGetModeratorURL;

typedef struct VidyoClientPrivateSoapOutEventGetModeratorURL_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the response (out event) - should be copy of in event.
	
	VidyoClientPrivateSoapResultCode result;											// Result of search request
	char moderatorURL[VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_URI_SIZE];						// Web cast URL
	VidyoBool hasPin;																	// hasPin : True if moderatorURL is pin enabled; False otherwise 
} VidyoClientPrivateSoapOutEventGetModeratorURL;

typedef struct VidyoClientPrivateSoapInEventGetRecordingId_
{
   VidyoUint typeRequest;
   VidyoUint requestId;
   char conferenceID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];					// conference ID
} VidyoClientPrivateSoapInEventGetRecordingId;

typedef struct VidyoClientPrivateSoapOutEventGetRecordingId_
{
   VidyoUint typeRequest;
   VidyoUint error;
   VidyoUint httpStatusCode;
   VidyoUint requestId;			// A unique request ID to match the response (out event) - should be copy of in event.
   VidyoClientPrivateSoapResultCode result;								// Result of search request
   VidyoInt recorderID;													// recorder ID
   char recorderName[VIDYO_CLIENT_PRIVATE_RECORDER_NAME_SIZE];			// Recorder Name
   VidyoBool recorderPaused;											// Indicates whether recorder is paused now
   VidyoBool webCast;													// Indicates whether webcast is on now
} VidyoClientPrivateSoapOutEventGetRecordingId;

typedef struct RecordingProfile_
{	
	char prefix[VIDYO_CLIENT_PRIVATE_SOAP_RECORDING_PROFILE_PREFIX_SIZE];
	char description[VIDYO_CLIENT_PRIVATE_SOAP_RECORDING_PROFILE_DESCRIPTION_SIZE];
} RecordingProfile;

typedef struct VidyoClientPrivateSoapInEventGetRecordingProfiles_
{
	VidyoUint typeRequest;
	VidyoUint requestId;									// A unique request ID to match the response (out event).
} VidyoClientPrivateSoapInEventGetRecordingProfiles;

typedef struct VidyoClientPrivateSoapOutEventGetRecordingProfiles_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;
	VidyoInt profileCount;
	RecordingProfile profiles[VIDYO_CLIENT_PRIVATE_SOAP_RECORDING_PROFILE_SIZE];
} VidyoClientPrivateSoapOutEventGetRecordingProfiles;

typedef struct VidyoClientPrivateSoapInEventStartRecording_
{
	VidyoUint typeRequest;
	VidyoUint requestId;									// A unique request ID to match the response (out event).

	char conferenceID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];
	char recorderPrefix[VIDYO_CLIENT_PRIVATE_SOAP_RECORDING_PROFILE_PREFIX_SIZE];
	VidyoBool webcast;
	char moderatorPin[VIDYO_CLIENT_PRIVATE_SOAP_PIN_SIZE];
} VidyoClientPrivateSoapInEventStartRecording;

typedef struct VidyoClientPrivateSoapOutEventStartRecording_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;
} VidyoClientPrivateSoapOutEventStartRecording;

typedef struct VidyoClientPrivateSoapInEventControlRecording_
{
	VidyoUint typeRequest;
	VidyoUint requestId;									// A unique request ID to match the response (out event).

	char conferenceID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];
	VidyoInt recorderID;
	char moderatorPin[VIDYO_CLIENT_PRIVATE_SOAP_PIN_SIZE];
} VidyoClientPrivateSoapInEventControlRecording;

typedef struct VidyoClientPrivateSoapOutEventControlRecording_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;
} VidyoClientPrivateSoapOutEventControlRecording;

typedef struct VidyoClientPrivateSoapInEventGetPortalPrefix_
{
	VidyoUint typeRequest;
	VidyoUint requestId;									// A unique request ID to match the response (out event).
} VidyoClientPrivateSoapInEventGetPortalPrefix;

typedef struct VidyoClientPrivateSoapOutEventGetPortalPrefix_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;
	char portalPrefix[VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_PREFIX_SIZE];
} VidyoClientPrivateSoapOutEventGetPortalPrefix;

typedef struct VidyoClientPrivateSoapInEventClearRaiseHand_
{
	VidyoUint typeRequest;
	VidyoUint requestId;									// A unique request ID to match the response (out event).

	VidyoBool raise;
} VidyoClientPrivateSoapInEventClearRaiseHand;

typedef struct VidyoClientPrivateSoapOutEventClearRaiseHand_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

} VidyoClientPrivateSoapOutEventClearRaiseHand;

typedef struct VidyoClientPrivateSoapInEventSetEndpointDetails_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char LongEID[VIDYO_CLIENT_PRIVATE_SOAP_LONG_EID_SIZE];
} VidyoClientPrivateSoapInEventSetEndpointDetails;

typedef struct VidyoClientPrivateSoapOutEventSetEndpointDetails_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of set end point features
} VidyoClientPrivateSoapOutEventSetEndpointDetails;

typedef struct VidyoClientPrivateSoapInEventLogoutAllOtherSessions_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

} VidyoClientPrivateSoapInEventLogoutAllOtherSessions;

typedef struct VidyoClientPrivateSoapOutEventLogoutAllOtherSessions_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of logout request all other sessions
} VidyoClientPrivateSoapOutEventLogoutAllOtherSessions;

typedef struct VidyoClientPrivateSoapInEventGetChangePasswordHtmlUrlWithToken_
{
	VidyoUint typeRequest;
	VidyoUint requestId;						// A unique request ID to match the response (out event) - should be copy of in event.

} VidyoClientPrivateSoapInEventGetChangePasswordHtmlUrlWithToken;

typedef struct VidyoClientPrivateSoapOutEventGetChangePasswordHtmlUrlWithToken_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of GetChangePasswordHtmlUrlWithToken
	char changePasswordHtmlUrl[VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_URI_SIZE];						// change password URL
} VidyoClientPrivateSoapOutEventGetChangePasswordHtmlUrlWithToken;

typedef struct VidyoClientPrivateSoapInEventDropAll_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char moderatorPin[PIN_SIZE];	// Optional moderator pin
	char conferenceId[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];
} VidyoClientPrivateSoapInEventDropAll;

typedef struct VidyoClientPrivateSoapOutEventDropAll_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;		// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of drop all request
} VidyoClientPrivateSoapOutEventDropAll;

typedef struct VidyoClientPrivateSoapInEventControlAudioServerAll_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.
	VidyoBool muteState;		// LMI_TRUE  for turn on privacy and LMI_FALSE for turn off privacy

	char moderatorPin[PIN_SIZE];	// Optional moderator pin
	char conferenceId[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];
} VidyoClientPrivateSoapInEventControlAudioServerAll;

typedef struct VidyoClientPrivateSoapOutEventControlAudioServerAll_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;		// A unique request ID to match the in and its corresponding out event - should be a copy of in event.
	VidyoBool muteState;		// LMI_TRUE  for turn on privacy and LMI_FALSE for turn off privacy

	VidyoClientPrivateSoapResultCode result;	// Result of audio unmute request
} VidyoClientPrivateSoapOutEventControlAudioServerAll;

typedef struct VidyoClientPrivateSoapInEventMuteAudioClientAll_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char moderatorPin[PIN_SIZE];	// Optional moderator pin
	char conferenceId[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];
} VidyoClientPrivateSoapInEventMuteAudioClientAll;

typedef struct VidyoClientPrivateSoapOutEventMuteAudioClientAll_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;		// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of audio mute request
} VidyoClientPrivateSoapOutEventMuteAudioClientAll;

typedef struct VidyoClientPrivateSoapInEventPrivacyControlServerAll_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.
	VidyoBool privacyOn;			// LMI_TRUE  for turn on privacy and LMI_FALSE for turn off privacy

	char moderatorPin[PIN_SIZE];	// Optional moderator pin
	char conferenceId[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];
} VidyoClientPrivateSoapInEventPrivacyControlServerAll;

typedef struct VidyoClientPrivateSoapOutEventPrivacyControlServerAll_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;		// A unique request ID to match the in and its corresponding out event - should be a copy of in event.
	VidyoBool privacyOn;		// LMI_TRUE  for turn on privacy and LMI_FALSE for turn off privacy

	VidyoClientPrivateSoapResultCode result;	// Result of privacy on request
} VidyoClientPrivateSoapOutEventPrivacyControlServerAll;

typedef struct VidyoClientPrivateSoapInEventPrivacyOnClientAll_
{
	VidyoUint typeRequest;
	VidyoUint requestId;			// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	char moderatorPin[PIN_SIZE];	// Optional moderator pin
	char conferenceId[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];
} VidyoClientPrivateSoapInEventPrivacyOnClientAll;

typedef struct VidyoClientPrivateSoapOutEventPrivacyOnClientAll_
{
	VidyoUint typeRequest;
	VidyoUint error;
	VidyoUint httpStatusCode;
	VidyoUint requestId;		// A unique request ID to match the in and its corresponding out event - should be a copy of in event.

	VidyoClientPrivateSoapResultCode result;	// Result of privacy on request
} VidyoClientPrivateSoapOutEventPrivacyOnClientAll;

/* End of type definitions used in SOAP interface */

typedef struct VidyoClientPrivateRequestSelfAccountData_
{
	VidyoBool dataValid;
	VidyoClientPrivateSoapAccountData data;
} VidyoClientPrivateRequestSelfAccountData;

/* Start of type definitions used in Portal Data Cache interface */

/*	The following are SOAP IN/OUT events that will leads to caching a local copy of portal data in client until 
	application requests to release the cache. */
typedef enum VidyoClientPrivatePortalDataCacheRequestType_
{
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_START = 1,	// To start building a portal data cache
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_COMPLETED,	// When start building a portal data cache is completed
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_RETRIEVE,	// To retrieve information from portal data cache
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_REFRESH,		// To refresh a portal data cache by retrieving it again from portal
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_RANGE_REFRESH,// To refresh a ranage of entries in portal data cache by retrieveing it again from portal
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_CLEAR,		// To clear a portal data cache
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_STOP,		// To drop all entries of a portal data cache
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_SHIFT,		// To shift left or right a portal data cache by retrieving next entries from portal
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_MANAGE,		// To add or delete specified entries from a portal data cache.
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_PAUSE,		// To pause an ongoing portal data cache retrieval.
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_RESUME,		// To resume a paused portal data cache retrieval.
	// To retrieve summary of portal data cache - only number of entries in cache. Not actual cache. No IN events for this
} VidyoClientPrivatePortalDataCacheRequestType;

typedef enum VidyoClientPrivatePortalDataCacheResult_
{
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_RESULT_SUCCESS=1,
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_RESULT_FAILURE,
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_RESULT_INVALID_REQ,
} VidyoClientPrivatePortalDataCacheResult;

typedef enum VidyoClientPrivatePortalDataCacheId_
{
	VIDYO_CLIENT_PRIVATE_CACHE_ALL_CONTACTS,// Cache corresponding to search all users based on a given search string
	VIDYO_CLIENT_PRIVATE_CACHE_MY_CONTACTS,	// Cache corresponding to search my contacts based on a given search string
	VIDYO_CLIENT_PRIVATE_CACHE_MY_ROOMS,	// Cache corresponding to search by my entity id for rooms owned by user based on a given search string
	VIDYO_CLIENT_PRIVATE_CACHE_MY_CONTACTS_ENTITY_ID,	// This is a special cache for entity ID of all my contacts. It is used for filterting all contacts
} VidyoClientPrivatePortalDataCacheId;

typedef enum VidyoClientPrivatePortalDataCacheActionType_
{
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_ACTION_TYPE_ADD=1,
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_ACTION_TYPE_DELETE,
} VidyoClientPrivatePortalDataCacheActionType;

typedef struct VidyoClientPrivatePortalDataCacheUserData_
{
	VidyoUint dataIndex;							// Data Id corresponding to data in Portal DB
	VidyoClientPrivateSoapAccountData accountData;	// Data contents
} VidyoClientPrivatePortalDataCacheUserData;

typedef struct VidyoClientPrivateInEventPortalDataCacheMandatoryPart_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
} VidyoClientPrivateInEventPortalDataCacheMandatoryPart;

/* The following shall be the first event to start caching portal data */
typedef struct VidyoClientPrivateInEventPortalDataCacheStart_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoUint requestId;										// A unique request ID to match the response (out event). This is optional
	VidyoClientPrivatePortalDataCacheId cacheId;				// Identify of cache whose caching is requested
	char searchString[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE]; // Search string - normally complete or partial user name
} VidyoClientPrivateInEventPortalDataCacheStart;

typedef struct VidyoClientPrivatePortalDataCacheUserDataRange_
{
	VidyoUint startIndex;	// Start index of data in cache
	VidyoUint endIndex;		// End index of data in cache
} VidyoClientPrivatePortalDataCacheUserDataRange;

/* Response for start portal data cache */
typedef struct VidyoClientPrivateOutEventPortalDataCacheStart_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoUint requestId;							// A unique request ID to match the response (out event). Copied from IN event.
	VidyoClientPrivatePortalDataCacheResult result;	// Result of search operation
	VidyoClientPrivatePortalDataCacheId cacheId;// Identify of cache that is started
	VidyoUint maxCacheEntries;					// Maximum number of user data can be stored in cache
	VidyoUint portalTotal;						// Total number of users matching the given search criteria in Portal
	VidyoUint numEntries;						// Total number of user data in cache now that can be retrieved
	VidyoClientPrivatePortalDataCacheUserDataRange dataRange; // Data range in cache now that can be retrieved
} VidyoClientPrivateOutEventPortalDataCacheStart;

/* Final response for start or refresh portal data caching request. This event is sent out when caching operation is complete  */
typedef struct VidyoClientPrivateOutEventPortalDataCacheCompleted_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoUint requestId;							// A unique request ID to match the response (out event). Copied from IN event.
	VidyoClientPrivatePortalDataCacheId cacheId;	// Identify of cache whose caching is completed
	VidyoClientPrivatePortalDataCacheResult result;	// Result of cache operation
	VidyoUint maxCacheEntries;						// Maximum number of user data can be stored in cache
	VidyoUint portalTotal;							// Total number of user data matching the given search criteria in Portal
	VidyoUint cacheTotal;							// Total number of user data in cache now that can be retrieved
	VidyoClientPrivatePortalDataCacheUserDataRange dataRange; // Data range in cache now that can be retrieved
} VidyoClientPrivateOutEventPortalDataCacheCompleted;

typedef struct VidyoClientPrivatePortalDataCacheRetrieveFilter_
{
	VidyoBool disabledRooms;						// Filter disabled room (VIDYO_TRUE - to filter/VIDYO_FALSE - do not filter)
	VidyoBool myContacts;							// Filter rooms that are in my contacts already (VIDYO_TRUE - to filter/VIDYO_FALSE - do not filter)
	VidyoBool myRooms;								// Filter rooms owned by me (VIDYO_TRUE - to filter/VIDYO_FALSE - do not filter)
} VidyoClientPrivatePortalDataCacheRetrieveFilter;

/* The following shall be the event to get data from cache */
typedef struct VidyoClientPrivateInEventPortalDataCacheRetrieve_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoClientPrivatePortalDataCacheId cacheId;	// Identify of cache from where the records to be retrieved
	VidyoUint requestId;							// Unique request ID - this value is copied to response.
	VidyoClientPrivatePortalDataCacheRetrieveFilter retrieveFilter;	// Filter to be applied for this retrieve
	VidyoUint startIndex;							// Starting number of the records to be retrieved
	VidyoUint numEntries;							// Number of records to be retrieved
} VidyoClientPrivateInEventPortalDataCacheRetrieve;

typedef enum VidyoClientPrivatePortalDataCacheSyncStatus_
{
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_SYNC_NOT_INITIATED=1,	// Data sync is not initiated
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_SYNC_ONGOING,	// Data sync is ongoing
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_SYNC_COMPLETE,	// Data sync is completed with no failure
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_SYNC_FAILURE,	// Data sync is completed with failure - Cache might have partial data
	VIDYO_CLIENT_PRIVATE_PORTAL_DATA_CACHE_SYNC_PAUSED,		// Data sync is paused - Cache might have partial data
} VidyoClientPrivatePortalDataCacheSyncStatus;

/* Direct access to read portal data cache */
typedef struct VidyoClientPrivateRetrievePortalDataCache_
{
	// Input to retrieve portal data cache.
	VidyoClientPrivatePortalDataCacheId cacheId;	// Identify of cache from where the records are retrieved
	VidyoUint startIndex;							// Starting number of the records to be retrieved or starting index in response
	VidyoUint numEntries;							// Number of records to be retrieved or number of records in response
	VidyoClientPrivatePortalDataCacheRetrieveFilter retrieveFilter;	// Filter to be applied for this retrieve

	// Output of retrieve portal data cache
	VidyoClientPrivatePortalDataCacheResult result;	// Result of search operation
	VidyoClientPrivatePortalDataCacheSyncStatus syncStatus;	// Status of data cache operation
	VidyoUint maxCacheEntries;						// Maximum number of user data can be stored in cache
	VidyoUint portalTotal;							// Total number of users matching the given search criteria in Portal
	VidyoUint cacheTotal;							// Total number of user data in cache now that can be retrieved
    VidyoClientPrivatePortalDataCacheUserData userData[VIDYO_CLIENT_PRIVATE_EVENT_PORTAL_DATA_CACHE_SIZE];
} VidyoClientPrivateRetrievePortalDataCache;

/* Response to the event to get data from cache */
typedef struct VidyoClientPrivateOutEventPortalDataCacheRetrieve_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoUint requestId;									// Unique request ID - this value is copied from request.
	VidyoClientPrivateRetrievePortalDataCache dataCache;	// Retrieved Portal Data cache information
} VidyoClientPrivateOutEventPortalDataCacheRetrieve;

/* Direct access to read portal data cache summary */
typedef struct VidyoClientPrivateRetrievePortalDataCacheSummary_
{
	// Input to retrieve portal data cache summary.
	VidyoClientPrivatePortalDataCacheId cacheId;	// Identify of cache from where the summary to be retrieved

	// Output of retrieve portal data cache
	VidyoClientPrivatePortalDataCacheResult result;	// Result of this retrieve operation
	char searchString[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE]; // Search string based on which this cache was built
	VidyoClientPrivatePortalDataCacheSyncStatus syncStatus;	// Status of data cache operation. 
	VidyoUint maxCacheEntries;						// Maximum number of user data can be stored in cache
	VidyoUint portalTotal;							// Total number of users matching the given search criteria in Portal DB
	VidyoUint cacheTotal;							// Total number of user data in cache now that can be retrieved
	VidyoClientPrivatePortalDataCacheUserDataRange dataRange; // Data range in cache now that can be retrieved
} VidyoClientPrivateRetrievePortalDataCacheSummary;

/* The following shall be the event to refresh the whole portal data cache.
   This is equivalent to restarting the cache built again. */
typedef struct VidyoClientPrivateInEventPortalDataCacheRefresh_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoUint requestId;									// A unique request ID to match the response (out event).
	VidyoClientPrivatePortalDataCacheId cacheId;			// Identify of cache to be refreshed
} VidyoClientPrivateInEventPortalDataCacheRefresh;

/* The following shall be the event to refresh a part of portal data cache.
   The part can be specified by a range. Number of entries in a range can be
   of any number of entries. */
typedef struct VidyoClientPrivateInEventPortalDataCacheRangeRefresh_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoUint requestId;						 // A unique request ID to match the response (out event).
	VidyoClientPrivatePortalDataCacheId cacheId; // Identify of cache to be refreshed
	VidyoUint startIndex;						 // Start index of data in cache to be refreshed
	VidyoUint numEntries;						 // Total number of user data in cache to be refreshed
} VidyoClientPrivateInEventPortalDataCacheRangeRefresh;

/* Response for refresh and RangeRefresh portal data cache */
typedef struct VidyoClientPrivateOutEventPortalDataCacheRefresh_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoUint requestId;							// A unique request ID to match the response (out event). Copied from IN event.
	VidyoClientPrivatePortalDataCacheId cacheId;	// Identify of cache that is refreshed
	VidyoClientPrivatePortalDataCacheResult result;	// Result of Refresh operation
	VidyoUint maxCacheEntries;						// Maximum number of user data can be stored in cache
	VidyoUint portalTotal;							// Total number of users matching the given search criteria in Portal
	VidyoUint cacheTotal;							// Total number of user data in cache now that can be retrieved
	VidyoClientPrivatePortalDataCacheUserDataRange dataRange; // Data range in cache now
} VidyoClientPrivateOutEventPortalDataCacheRefresh;

/* The following shall be the event to stop an ongoing portal data caching */
typedef struct VidyoClientPrivateInEventPortalDataCacheStop_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoClientPrivatePortalDataCacheId cacheId;	// Identify of cache whose caching to be stopped
} VidyoClientPrivateInEventPortalDataCacheStop;

/* Response for stop portal data caching request */
typedef struct VidyoClientPrivateOutEventPortalDataCacheStop_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoClientPrivatePortalDataCacheId cacheId;	// Identify of cache whose caching is to be stopped
	VidyoClientPrivatePortalDataCacheResult result;	// Result of stop operation
} VidyoClientPrivateOutEventPortalDataCacheStop;

/* The following shall be the event to clear a portal data cache */
typedef struct VidyoClientPrivateInEventPortalDataCacheClear_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoClientPrivatePortalDataCacheId cacheId;	// Identify of cache to be cleared
} VidyoClientPrivateInEventPortalDataCacheClear;

/* Response for clear portal data caching request */
typedef struct VidyoClientPrivateOutEventPortalDataCacheClear_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoClientPrivatePortalDataCacheId cacheId;	// Identify of cache to be cleared
	VidyoClientPrivatePortalDataCacheResult result;	// Result of cache clear operation
} VidyoClientPrivateOutEventPortalDataCacheClear;

typedef enum VidyoClientPrivatePortalDataCacheShiftType_
{
	VIDYO_CLIENT_PRIVATE_PORTAL_CACHE_SHIFT_FORWARD=1,	// Shift cache forward
	VIDYO_CLIENT_PRIVATE_PORTAL_CACHE_SHIFT_BACKWARD,	// Shift cache backward
} VidyoClientPrivatePortalDataCacheShiftType;

/* The following shall be the event to shift a portal data cache */
typedef struct VidyoClientPrivateInEventPortalDataCacheShift_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoUint requestId;									// A unique request ID to match the response (out event).
	VidyoClientPrivatePortalDataCacheId cacheId;			// Identify of cache to be shifted forward or backward
	VidyoClientPrivatePortalDataCacheShiftType shiftType;	// Shift cache data forward or backward
	VidyoUint numEntries;									// Number of records by which the cache to be shifted
} VidyoClientPrivateInEventPortalDataCacheShift;

/* Response for stop portal data caching request */
typedef struct VidyoClientPrivateOutEventPortalDataCacheShift_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoUint requestId;									// A unique request ID to match the response (out event). Copied from IN event.
	VidyoClientPrivatePortalDataCacheId cacheId;			// Identify of cache to be shifted forward or backward
	VidyoClientPrivatePortalDataCacheResult result;			// Result of cache shift operation
	VidyoUint maxCacheEntries;								// Maximum number of user data can be stored in cache
	VidyoUint portalTotal;									// Total number of user data matching the given search criteria in Portal
	VidyoUint cacheTotal;									// Total number of user data in cache
	VidyoClientPrivatePortalDataCacheUserDataRange dataRange; // Data range in cache now
} VidyoClientPrivateOutEventPortalDataCacheShift;

/* The following shall be the event to manage (add or delete an entry) to a portal data cache.
   This is supported only for cache id = VIDYO_CLIENT_PRIVATE_CACHE_MY_CONTACTS_ENTITY_ID now.
   There is no respose send to this event */
typedef struct VidyoClientPrivateInEventPortalDataCacheManage_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoUint requestId;									// A unique request ID to match the response (out event).
	VidyoClientPrivatePortalDataCacheId cacheId;			// Identify of cache to be shifted forward or backward
	VidyoClientPrivatePortalDataCacheActionType actionType; // Action to be performed on portal data cache.
	char entityID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];		// Entity ID of the entry to be deleted or added.
} VidyoClientPrivateInEventPortalDataCacheManage;

/* The following shall be the event to pause a portal data cache */
typedef struct VidyoClientPrivateInEventPortalDataCachePause_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoClientPrivatePortalDataCacheId cacheId;	// Identify of cache to be paused
	VidyoUint requestId;							// A unique request ID to match the response (out event).
} VidyoClientPrivateInEventPortalDataCachePause;

/* Response for pause portal data caching request */
typedef struct VidyoClientPrivateOutEventPortalDataCachePause_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoClientPrivatePortalDataCacheId cacheId;	// Identify of cache paused
	VidyoClientPrivatePortalDataCacheResult result;	// Result of cache pause operation
	VidyoUint requestId;							// A unique request ID to match the response (out event).
} VidyoClientPrivateOutEventPortalDataCachePause;

/* The following shall be the event to resume a portal data cache */
typedef struct VidyoClientPrivateInEventPortalDataCacheResume_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoClientPrivatePortalDataCacheId cacheId;	// Identify of cache to be Resumed
	VidyoUint requestId;							// A unique request ID to match the response (out event).
} VidyoClientPrivateInEventPortalDataCacheResume;

typedef struct VidyoClientPrivateInEventSetBoolFlag_
{
	VidyoBool setBool;
} VidyoClientPrivateInEventSetBoolFlag;

/*! Event structure used to start speaker test in pre-call for VidyoWeb
 *  This structure is ONLY used by VidyoWeb client to communicate with VidyoWeb Plugin
 
 - Used by following in events:
 + #VIDYO_CLIENT_IN_EVENT_START_PRECALL_TEST_SPEAKER
 */
typedef struct VidyoClientPrivateInEventStartPrecallTestSpeaker_
{
	/* This file name is used for VidyoWeb to pass the filename to the plugin. this is not used
	 * directly by the vidyoclient
	 */
	char soundFileName[VIDYO_MAX_PATH];
} VidyoClientPrivateInEventStartPrecallTestSpeaker;

/* Response for resume portal data caching request */
typedef struct VidyoClientPrivateOutEventPortalDataCacheResume_
{
	VidyoClientPrivatePortalDataCacheRequestType typeRequest;
	VidyoClientPrivatePortalDataCacheId cacheId;	// Identify of cache resume
	VidyoClientPrivatePortalDataCacheResult result;	// Result of cache resume operation
	VidyoUint requestId;							// A unique request ID to match the response (out event).
} VidyoClientPrivateOutEventPortalDataCacheResume;

/* End of type definitions used in Portal Data Cache interface */

/* List of optional features supported by portal */
typedef struct VidyoClientPrivatePortalFeatures_
{
	VidyoUint featureCount;
	VidyoClientPrivateSoapPortalFeatures features[VIDYO_CLIENT_PRIVATE_SOAP_PORTALFEATURE_NUM];
} VidyoClientPrivatePortalFeatures;


/* Used for VIDYO_CLIENT_PRIVATE_OUT_EVENT_LOG */
typedef struct VidyoClientPrivateOutEventLog_
{
	char message[MAX_LOG_LEN];
} VidyoClientPrivateOutEventLog;

/* Start of type definitions used in Remote control interface */

typedef struct VidyoClientPrivateRequestGetGenericStringConfig_
{
	VidyoVoidPtr requestDataOutput;
	VidyoSizeT requestDataOutputSize;
} VidyoClientPrivateRequestGetGenericStringConfig;

typedef struct VidyoClientPrivateRequestGetVidyoClientVersion_
{
	VidyoUint8 version[VIDYO_CLIENT_VERSION_SIZE];
} VidyoClientPrivateRequestGetVidyoClientVersion;

/* End of type definitions used in Remote control interface */

typedef struct VidyoClientPrivatePortalAccountInfo_
{
	char portalUri[VIDYO_CLIENT_PRIVATE_SOAP_PORTAL_URI_SIZE];
	char userName[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE];
} VidyoClientPrivatePortalAccountInfo;

#ifdef HUNTER_ROOM
typedef enum 
{
	HKEY_SELF_VIEW= WM_USER + 277,
	HKEY_PRIVACY,
	HKEY_SETTINGS,
	HKEY_SHARE,
	HKEY_TOGGLE,
	HKEY_CONNECT,
	HKEY_DISCONNECT,
	HKEY_MUTE,
	HKEY_HOME,
	HKEY_BACK,
	HKEY_RIGHT,
	HKEY_LEFT,
	HKEY_UP,
	HKEY_DOWN,
	HKEY_PLUS,
	HKEY_MINUS,
	HKEY_MANAGE,
	HKEY_PGUP,
	HKEY_PGDOWN,
	HKEY_ENTER,
	HKEY_BACKSPACE,
	HKEY_A,
	HKEY_B,
	HKEY_C,
	HKEY_D,

	HKEY_0,
	HKEY_1,	HKEY_2,	HKEY_3,
	HKEY_4,	HKEY_5,	HKEY_6,
	HKEY_7,	HKEY_8,	HKEY_9,
	HKEY_DEVIDE,HKEY_STAR,

	HKEY_QUIT,
	HKEY_STATUS,
	HKEY_RESET,
	HKEY_RESET_HOME,
	HKEY_BACKLIGHT_ON,
	HKEY_BACKLIGHT_OFF,
	HKEY_MONITOR_720,
	HKEY_MONITOR_1080,
	HKEY_LOST_ENDPOINT, // Fake hot key used by FECC
	HKEY_OVERSCAN,
	HKEY_K,
} HotKeysHunterRoom;

typedef enum
{
	USB_CAPTURE_POSSIBLE = 11,
	USB_CAPTURE_ERROR,
	USB_CAPTURE_STARTED,
	USB_CAPTURE_STOPPED,
	USB_CAPTURE_NONE,
	USB_CAPTURE_GET_LP,
} AppVga2UsbEvent;
typedef enum
{
	USB_RESOLUTION_CHANGED = 0,
	USB_ERROR_VIDEOMODE,
	USB_NO_VIDEO,
	USB_ERROR_GRAB_FRAME,
	USB_RESOLUTION_HUGE,
	USB_NO_DEVICE,
} AppVga2UsbError;
typedef struct
{
	AppVga2UsbEvent evnt;
	int width;
	int height;
	int error_code;
} AppVga2UsbMesage;
#endif // HUNTER_ROOM

typedef struct
{
	VidyoUint tglMonitors;
	VidyoUint numMonitors; // Number of monitors we are using at the current time
	VidyoUint reqMonitors; // Number of monitors we want to use at current time
	VidyoUint cfgMonitors; // Number of monitors we are configured to use
	VidyoUint availMonitors; // Number of monitors that are available
	VidyoUint seqMon[3];
	VidyoBool forceFocus; // Special case for HD100 dual screen switch
}
AppGuiMonitorParams;

typedef struct
{
	VidyoImageFormat imageFormat;
	VidyoUint width;
	VidyoUint height;
	VidyoUint8* pMem;
}
AppGuiImageParams;

#ifdef HUNTER_ROOM
typedef struct
{
	VidyoInt prevOn;
	VidyoUint monitor;
	VidyoUint mode;
	VidyoUint position;
	VidyoUint numMonitors;
}
AppGuiPreviewParams;

// Used by RemoteShareEnabled()
DWORD GetRoomPlatform(VidyoInt registryVal = LMI_FALSE);
//void ChangeFocus(AppGui *gui,int toMe);

#define PLATFORM_HD220 220
#define PLATFORM_HD210 210
#define PLATFORM_HD200 200
#define PLATFORM_HD100 100
#define PLATFORM_HD50   50
#endif // HUNTER_ROOM

// Network Control AppGui event
typedef struct
{
	char ext[32];
	VidyoUint code;
} NetworkControlEvent;


/*
 Used by:
  VIDYO_CLIENT_PRIVATE_IN_EVENT_GET_CONFIGURATION
  VIDYO_CLIENT_PRIVATE_IN_EVENT_SET_CONFIGURATION
  VIDYO_CLIENT_PRIVATE_OUT_EVENT_GET_CONFIGURATION_RESPONSE
*/
typedef struct VidyoClientEventConfiguration_
{
	VidyoVoidPtr callerID;	// the ID of the caller - to be defined by the user
	VidyoClientRequestConfiguration config;
} VidyoClientEventConfiguration;

/*
 Used by:
  VIDYO_CLIENT_PRIVATE_REQUEST_DO_PUSH_CAPTURED_AUDIO_FRAME
  VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_PULL_AUDIO_FRAME_FOR_PLAYBACK
*/
typedef struct VidyoClientPrivateRequestPushAudioBuffer_
{
	VidyoVoidPtr frame;
	VidyoInt numSamples;
	VidyoInt sampleRate;
	VidyoInt numChannels;
	VidyoInt bitsPerSample;
	VidyoBool success;
} VidyoClientPrivateRequestPushAudioBuffer;

/*
 Used by:
  VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_DO_PUSH_CAPTURED_VIDEO_FRAME
 */
// typedef struct VidyoClientPrivateRequestVideoFrame_
// {
// 	VidyoVoidPtr frame;
// 	const char* fourCC;
// 	VidyoInt width;
// 	VidyoInt height;
// 	VidyoInt rotation;
// 	VidyoBool mirrored;
// 	VidyoBool success;
// } VidyoClientPrivateRequestVideoFrame;

/*
 Used by:
 VIDYO_CLIENT_PRIVATE_REQUEST_GET_ENTITY_INFO
 */
typedef struct VidyoClientPrivateRequestEntityInfo_
{
	char entityID[VIDYO_CLIENT_PRIVATE_SOAP_EID_SIZE];// Entity ID - Unique in Portal DB
	char displayName[VIDYO_CLIENT_PRIVATE_SOAP_USERNAME_SIZE];	// Display Name
} VidyoClientPrivateRequestEntityInfo;

/*
Used by:
VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_SET_HAS_CAMERA
TEMPORARY until SDK supports front/back cameras
*/
typedef struct VidyoClientPrivateRequestSetHasCamera_
{
	VidyoBool hasFrontCamera;
	VidyoBool hasBackCamera;
} VidyoClientPrivateRequestSetHasCamera;

/*
 Used by:
 VIDYO_CLIENT_PRIVATE_REQUEST_GET_VIDEO_CAPTURE_CAPABILITIES
 */
typedef struct VidyoClientPrivateRequestVideoCaptureCapabilities_
{
	VidyoClientVideoPreferences	preference;		// Preference this capability satisfies
	VidyoUint width;
	VidyoUint height;
    VidyoUint minFrameRate;
} VidyoClientPrivateRequestVideoCaptureCapabilities;

/*
 Used by:
VIDYO_CLIENT_PRIVATE_REQUEST_GET_VIDEO_CAPTURE_CAPABILITIES
*/
#define VIDEOCAPABILITIES_MAX 3
typedef struct VidyoClientPrivateRequestGetVideoCaptureCapabilities_
{
	VidyoUint	device;
	VidyoBool	isFrontCamera;		// Android: Need to know if front camera or not
	VidyoUint	capsCount;
	VidyoClientPrivateRequestVideoCaptureCapabilities caps[VIDEOCAPABILITIES_MAX];
} VidyoClientPrivateRequestGetVideoCaptureCapabilities;

/*
Used by:
VIDYO_CLIENT_PRIVATE_OUT_EVENT_WEBPROXY_UPDATE_NEEDED
*/
typedef struct VidyoClientPrivateOutEventWebProxyUpdateNeeded_
{
	char webProxyURL[URI_LEN];
} VidyoClientPrivateOutEventWebProxyUpdateNeeded;

/*
Used by:
VIDYO_CLIENT_PRIVATE_REQUEST_ANDROID_SET_WEB_PROXY_DYNAMIC_VALUES
*/
#define PACLIST_LEN	5
#define PACTYPE_LEN	8
typedef struct VidyoClientPrivateRequestWebProxyDynamic_
{
	char webProxyNetAddress[URI_LEN];
	char webProxyNetPort[SERVERPORT_SIZE];

	char webProxyPacDestURL[PACLIST_LEN][URI_LEN];
	char webProxyPacType[PACLIST_LEN][PACTYPE_LEN];
	char webProxyPacAddress[PACLIST_LEN][URI_LEN];
	char webProxyPacPort[PACLIST_LEN][SERVERPORT_SIZE];
} VidyoClientPrivateRequestWebProxyDynamic;

/*
Used by:
VIDYO_CLIENT_PRIVATE_REQUEST_SET_PIXEL_DENSITY
*/
typedef struct VidyoClientPrivateRequestSetPixelDensity_
{
	double density;
} VidyoClientPrivateRequestSetPixelDensity;

/*
Used by:
VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_GET_VIDEO_DOCK_COUNT
VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_GET_APPLICATION_DOCK_COUNT
*/
typedef struct VidyoClientPrivateRequestGetDockCount_
{
	VidyoInt count;
} VidyoClientPrivateRequestGetDockCount;

/*
Used by:
VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_SET_STATS_VISIBILITY
VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_GET_STATS_VISIBILITY
VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_SET_LABELS_VISIBILITY
VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_GET_LABELS_VISIBILITY
 */
typedef struct VidyoClientPrivateRequestVisibility_
{
	VidyoBool visibility;	// Set to true if visible, false otherwise
} VidyoClientPrivateRequestVisibility;

/*
Used by:
VIDYO_CLIENT_PRIVATE_REQUEST_MOBILE_CALL_ON_HOLD
 */
typedef struct VidyoClientPrivateRequestPutCallOnHold_
{
	VidyoBool onHold;	// Set to true if on hold, false otherwise
} VidyoClientPrivateRequestPutCallOnHold;


/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_PRIVATE_REQUEST_GET_AEC_AGC_INFORMATION
*/
typedef struct VidyoClientPrivateRequestAecAgcInformation_
{
	/*!
		Configured AEC and AGC method.  @see VidyoClientAecAgcMethod.
	*/
	VidyoClientAecAgcMethod configuredAecAgcMethod;
	/*!
		AEC status - AEC configuration status.
	*/
	VidyoBool configuredAecStatus;
	/*!
		AGC status - AGC configuration status.
	*/
	VidyoBool configuredAgcStatus;
	/*!
		Status to show whether AEC is supported in OS. Valid only when configuredAecAgcMethod is OS_INTERNAL_AEC_AGC, active in call with a microphone is selected.
	*/
	VidyoBool hasOsAecSupported;
	/*!
		Status to show whether AGC is supported in OS. Valid only when configuredAecAgcMethod is OS_INTERNAL_AEC_AGC, active in call with a microphone is selected.
	*/
	VidyoBool hasOsAgcSupported;
	/*!
		Status to show whether AEC is settable in currently selected microphone.  Valid only when configuredAecAgcMethod is OS_INTERNAL_AEC_AGC, active in call with a microphone is selected.
	*/
	VidyoBool hasOsAecSettable;
	/*!
		Status to show whether AGC is settable in currently selected microphone.  Valid only when configuredAecAgcMethod is OS_INTERNAL_AEC_AGC, active in call with a microphone is selected.
	*/
	VidyoBool hasOsAgcSettable;
	/*!
		Active call state flag
	*/
	VidyoBool inActiveCall;
	/*!
		Has a valid microphone in use flag
	*/
	VidyoBool hasValidMicrophone;
	/*!
		AEC status - Current OS AEC status. Valid only when active in a call & a microphone is selected.
	*/
	VidyoBool currentOsAecStatus;
	/*!
		AGC status - Current OS AGC status. Valid only when active in a call & a microphone is selected.
	*/
	VidyoBool currentOsAgcStatus;
	/*!
		AEC status - Current Vidyo AEC status. Valid only when active in a call & a microphone is selected.
	*/
	VidyoBool currentVidyoAecStatus;
	/*!
		AGC status - Current Vidyo AGC status. Valid only when active in a call & a microphone is selected.
	*/
	VidyoBool currentVidyoAgcStatus;
} VidyoClientPrivateRequestAecAgcInformation;

typedef enum VidyoClientPrivateDeviceSelectionPreferenceValue_
{
	SELECT_SYSTEM_DEFAULT_DEVICE,	// Select the system default device when there is no history
	SELECT_PREFERRED_DEVICE,		// Select a preferred device if available when there is no history
	NO_PREFERENCE,					// No preference - so keep default value
} VidyoClientPrivateDeviceSelectionPreferenceValue;

typedef struct VidyoClientPrivateDeviceSelectionPreference_
{
	VidyoClientPrivateDeviceSelectionPreferenceValue firstTime;		// Device selection preference during initialization and when there is no history or history does not match
	VidyoClientPrivateDeviceSelectionPreferenceValue subsequentTime;// Device selection preference after initialization and when there is no history or history does not match
} VidyoClientPrivateDeviceSelectionPreference;

/*
 Used by:
 VIDYO_CLIENT_PRIVATE_REQUEST_GET_LECTURE_MODE_STATUS
 */
typedef struct VidyoClientPrivateLectureModeStatus_
{
	VidyoBool inLectureMode;
	VidyoBool inPresenterMode;
	VidyoBool isTherePresenter;
} VidyoClientPrivateLectureModeStatus;

/*! Event structure
	- Used by following out events:
		+ #VIDYO_CLIENT_PRIVATE_REQUEST_CONTROL_RESOURCE_MONITORING
*/
typedef struct VidyoClientPrivateControlResourceMonitoring_
{
	/*!
		Disable CPU resource monitoring
	*/
	VidyoBool disableCpuResourceMonitoring;
	/*!
		Disable RX resource monitoring
	*/
	VidyoBool disableRxBwResourceMonitoring;
} VidyoClientPrivateControlResourceMonitoring;

void VidyoClientPrivateSetDeviceSelectionPreference(VidyoClientPrivateDeviceSelectionPreference *deviceSelectionPreferences);
VidyoBool VidyoClientIsCurrentlyRunning();

#if defined(__cplusplus)
extern "C" {
#endif

DECLSPEC void VidyoClientPrivateSetMaxLogFiles(VidyoUint numberOfLogFiles);

#if defined(__cplusplus)
}
#endif

#define CLIENT_OUT_MESSAGES_ENUMRATION(DO)						\
	DO(VIDYO_CLIENT_OUT_EVENT_MIN)								\
	DO(VIDYO_CLIENT_OUT_EVENT_USER_MESSAGE)						\
	DO(VIDYO_CLIENT_OUT_EVENT_LOGIC_STARTED)					\
	DO(VIDYO_CLIENT_OUT_EVENT_SIGN_IN)							\
	DO(VIDYO_CLIENT_OUT_EVENT_SIGN_OUT)							\
	DO(VIDYO_CLIENT_OUT_EVENT_SUBSCRIBING)						\
	DO(VIDYO_CLIENT_OUT_EVENT_APP_EXIT)							\
	DO(VIDYO_CLIENT_OUT_EVENT_DEVICE_SELECT)					\
	DO(VIDYO_CLIENT_OUT_EVENT_DEVICES_CHANGED)					\
	DO(VIDYO_CLIENT_OUT_EVENT_RINGING)							\
	DO(VIDYO_CLIENT_OUT_EVENT_RING_PROGRESS)					\
	DO(VIDYO_CLIENT_OUT_EVENT_END_RINGING)						\
	DO(VIDYO_CLIENT_OUT_EVENT_CALLING)							\
	DO(VIDYO_CLIENT_OUT_EVENT_CALL_PROGRESS)					\
	DO(VIDYO_CLIENT_OUT_EVENT_END_CALLING)						\
	DO(VIDYO_CLIENT_OUT_EVENT_JOINING)							\
	DO(VIDYO_CLIENT_OUT_EVENT_JOIN_PROGRESS)					\
	DO(VIDYO_CLIENT_OUT_EVENT_RETRYING)							\
	DO(VIDYO_CLIENT_OUT_EVENT_END_PROCESSING)					\
	DO(VIDYO_CLIENT_OUT_EVENT_CONFERENCE_ACTIVE)				\
	DO(VIDYO_CLIENT_OUT_EVENT_CONFERENCE_ENDED)					\
	DO(VIDYO_CLIENT_OUT_EVENT_INCOMING_CALL)					\
	DO(VIDYO_CLIENT_OUT_EVENT_END_INCOMING_CALL)				\
	DO(VIDYO_CLIENT_OUT_EVENT_PREVIEW)							\
	DO(VIDYO_CLIENT_OUT_EVENT_MUTED_AUDIO_IN)					\
	DO(VIDYO_CLIENT_OUT_EVENT_MUTED_AUDIO_OUT)					\
	DO(VIDYO_CLIENT_OUT_EVENT_MUTED_VIDEO)						\
	DO(VIDYO_CLIENT_OUT_EVENT_MUTED_SERVER_AUDIO_IN)			\
	DO(VIDYO_CLIENT_OUT_EVENT_MUTED_SERVER_VIDEO)				\
	DO(VIDYO_CLIENT_OUT_EVENT_ADD_SHARE)						\
	DO(VIDYO_CLIENT_OUT_EVENT_REMOVE_SHARE)						\
	DO(VIDYO_CLIENT_OUT_EVENT_SHARE_CLOSED)						\
	DO(VIDYO_CLIENT_OUT_EVENT_RESIZE)							\
	DO(VIDYO_CLIENT_OUT_EVENT_PARTICIPANTS_LIMIT)				\
	DO(VIDYO_CLIENT_OUT_EVENT_ECHO_DETECTED)					\
	DO(VIDYO_CLIENT_OUT_EVENT_KEYDOWN)							\
	DO(VIDYO_CLIENT_OUT_EVENT_KEYUP)							\
	DO(VIDYO_CLIENT_OUT_EVENT_MOUSE_DOWN)						\
	DO(VIDYO_CLIENT_OUT_EVENT_MOUSE_UP)							\
	DO(VIDYO_CLIENT_OUT_EVENT_MOUSE_MOVE)						\
	DO(VIDYO_CLIENT_OUT_EVENT_MOUSE_SCROLL)						\
	DO(VIDYO_CLIENT_OUT_EVENT_FECC_LIST_UPDATED)				\
	DO(VIDYO_CLIENT_OUT_EVENT_CONTROL_CAMERA)					\
	DO(VIDYO_CLIENT_OUT_EVENT_SET_PARTICIPANT_VIDEO_MODE_DONE)	\
	DO(VIDYO_CLIENT_OUT_EVENT_CONFERENCE_INFO_UPDATE)			\
	DO(VIDYO_CLIENT_OUT_EVENT_MEDIA_CONTROL)					\
	DO(VIDYO_CLIENT_OUT_EVENT_LOGIN)							\
	DO(VIDYO_CLIENT_OUT_EVENT_LICENSE)							\
	DO(VIDYO_CLIENT_OUT_EVENT_LINKED)							\
	DO(VIDYO_CLIENT_OUT_EVENT_SIGNED_IN)						\
	DO(VIDYO_CLIENT_OUT_EVENT_SIGNED_OUT)						\
	DO(VIDYO_CLIENT_OUT_EVENT_MAX)		
							


#endif // VIDYO_CLIENT_PRIVATE_H

