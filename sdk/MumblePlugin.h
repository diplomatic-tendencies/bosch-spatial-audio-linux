#ifdef MUMBLE_PLUGIN_NO_DEFAULT_FUNCTION_DEFINITIONS
#undef EXTERNAL_MUMBLE_PLUGIN_DEFAULT_IMPLEMENTATIONS_
#define EXTERNAL_MUMBLE_PLUGIN_DEFAULT_IMPLEMENTATIONS_ 
#endif
#undef MUMBLE_PLUGIN_CREATE_MUMBLE_API_TYPEDEF
#ifndef MUMBLE_PLUGIN_NO_API_TYPEDEF
#define MUMBLE_PLUGIN_CREATE_MUMBLE_API_TYPEDEF 
#endif
#ifndef EXTERNAL_MUMBLE_PLUGIN_MACROS_
#define EXTERNAL_MUMBLE_PLUGIN_MACROS_ 
#define MUMBLE_PLUGIN_INTERFACE_MAJOR_MACRO 1
#define MUMBLE_PLUGIN_INTERFACE_MINOR_MACRO 2
#define MUMBLE_PLUGIN_INTERFACE_PATCH_MACRO 0
# ifndef MUMBLE_PLUGIN_API_MAJOR_MACRO
#define MUMBLE_PLUGIN_API_MAJOR_MACRO 1
# endif
# ifndef MUMBLE_PLUGIN_API_MINOR_MACRO
#define MUMBLE_PLUGIN_API_MINOR_MACRO 2
# endif
# ifndef MUMBLE_PLUGIN_API_PATCH_MACRO
#define MUMBLE_PLUGIN_API_PATCH_MACRO 0
# endif
#define MUMBLE_PLUGIN_FUNCTIONS_MAJOR_MACRO 1
#define MUMBLE_PLUGIN_FUNCTIONS_MINOR_MACRO 1
#define MUMBLE_PLUGIN_FUNCTIONS_PATCH_MACRO 0
# if defined(__GNUC__) && !defined(__MINGW32__)
#define MUMBLE_PLUGIN_EXPORT __attribute__((visibility("default")))
# elif defined(_MSC_VER)
#define MUMBLE_PLUGIN_EXPORT __declspec(dllexport)
# elif defined(__MINGW32__)
#define MUMBLE_PLUGIN_EXPORT __attribute__((dllexport))
# else
# error No MUMBLE_PLUGIN_EXPORT definition available
# endif
# if defined(_MSC_VER)
#define MUMBLE_PLUGIN_CALLING_CONVENTION __cdecl
# elif defined(__MINGW32__)
#define MUMBLE_PLUGIN_CALLING_CONVENTION __attribute__((cdecl))
# else
#define MUMBLE_PLUGIN_CALLING_CONVENTION 
# endif
# if defined(QT_CORE_LIB) || defined(QT_VERSION)
#define MUMBLE_PLUGIN_HAS_QT 
# endif
#define MUMBLE_PLUGIN_VERSION_CHECK(major,minor,patch) (((major) << 16) | ((minor) << 8) | (patch))
# ifdef __cplusplus
#define MUMBLE_PLUGIN_CONSTEXPR constexpr
# else
#define MUMBLE_PLUGIN_CONSTEXPR 
# endif
# ifdef __cplusplus
#define MUMBLE_EXTERN_C_BEGIN extern "C" {
#define MUMBLE_EXTERN_C_END }
# else
#define MUMBLE_EXTERN_C_BEGIN 
#define MUMBLE_EXTERN_C_END 
# endif
#define MUMBLE_CONCAT(a,b) a ##_ ##b
#define MUMBLE_ECONCAT(a,b) MUMBLE_CONCAT(a, b)
#define MUMBLE_QUOTE(arg) #arg
#define MUMBLE_EQUOTE(arg) MUMBLE_QUOTE(arg)
#endif
#ifndef EXTERNAL_MUMBLE_PLUGIN_TYPES_
#define EXTERNAL_MUMBLE_PLUGIN_TYPES_ 
# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# ifdef __cplusplus
# include <string>
# ifdef MUMBLE_PLUGIN_HAS_QT
# include <QString>
# endif
# endif
MUMBLE_EXTERN_C_BEGIN
enum Mumble_PluginFeature {
 MUMBLE_FEATURE_NONE = 0,
 MUMBLE_FEATURE_POSITIONAL = 1 << 0,
 MUMBLE_FEATURE_AUDIO = 1 << 1,
};
enum Mumble_TalkingState {
 MUMBLE_TS_INVALID = -1,
 MUMBLE_TS_PASSIVE = 0,
 MUMBLE_TS_TALKING,
 MUMBLE_TS_WHISPERING,
 MUMBLE_TS_SHOUTING,
 MUMBLE_TS_TALKING_MUTED,
};
enum Mumble_TransmissionMode {
 MUMBLE_TM_CONTINOUS,
 MUMBLE_TM_VOICE_ACTIVATION,
 MUMBLE_TM_PUSH_TO_TALK,
};
enum Mumble_ErrorCode {
 MUMBLE_EC_INTERNAL_ERROR = -2,
 MUMBLE_EC_GENERIC_ERROR = -1,
 MUMBLE_EC_OK = 0,
 MUMBLE_EC_POINTER_NOT_FOUND,
 MUMBLE_EC_NO_ACTIVE_CONNECTION,
 MUMBLE_EC_USER_NOT_FOUND,
 MUMBLE_EC_CHANNEL_NOT_FOUND,
 MUMBLE_EC_CONNECTION_NOT_FOUND,
 MUMBLE_EC_UNKNOWN_TRANSMISSION_MODE,
 MUMBLE_EC_AUDIO_NOT_AVAILABLE,
 MUMBLE_EC_INVALID_SAMPLE,
 MUMBLE_EC_INVALID_PLUGIN_ID,
 MUMBLE_EC_INVALID_MUTE_TARGET,
 MUMBLE_EC_CONNECTION_UNSYNCHRONIZED,
 MUMBLE_EC_INVALID_API_VERSION,
 MUMBLE_EC_UNSYNCHRONIZED_BLOB,
 MUMBLE_EC_UNKNOWN_SETTINGS_KEY,
 MUMBLE_EC_WRONG_SETTINGS_TYPE,
 MUMBLE_EC_SETTING_WAS_REMOVED,
 MUMBLE_EC_DATA_TOO_BIG,
 MUMBLE_EC_DATA_ID_TOO_LONG,
 MUMBLE_EC_API_REQUEST_TIMEOUT,
 MUMBLE_EC_OPERATION_UNSUPPORTED_BY_SERVER,
};
enum Mumble_PositionalDataErrorCode {
 MUMBLE_PDEC_OK = 0,
 MUMBLE_PDEC_ERROR_TEMP,
 MUMBLE_PDEC_ERROR_PERM,
};
enum Mumble_SettingsKey {
 MUMBLE_SK_INVALID = -1,
 MUMBLE_SK_AUDIO_INPUT_VOICE_HOLD = 0,
 MUMBLE_SK_AUDIO_INPUT_VAD_SILENCE_THRESHOLD = 1,
 MUMBLE_SK_AUDIO_INPUT_VAD_SPEECH_THRESHOLD = 2,
 MUMBLE_SK_AUDIO_OUTPUT_PA_MINIMUM_DISTANCE = 3,
 MUMBLE_SK_AUDIO_OUTPUT_PA_MAXIMUM_DISTANCE = 4,
 MUMBLE_SK_AUDIO_OUTPUT_PA_BLOOM = 5,
 MUMBLE_SK_AUDIO_OUTPUT_PA_MINIMUM_VOLUME = 6,
};
enum Mumble_KeyCode {
 MUMBLE_KC_INVALID = -1,
 MUMBLE_KC_NULL = 0,
 MUMBLE_KC_END = 1,
 MUMBLE_KC_LEFT = 2,
 MUMBLE_KC_RIGHT = 4,
 MUMBLE_KC_UP = 5,
 MUMBLE_KC_DOWN = 6,
 MUMBLE_KC_DELETE = 7,
 MUMBLE_KC_BACKSPACE = 8,
 MUMBLE_KC_TAB = 9,
 MUMBLE_KC_ENTER = 10,
 MUMBLE_KC_ESCAPE = 27,
 MUMBLE_KC_PAGE_UP = 11,
 MUMBLE_KC_PAGE_DOWN = 12,
 MUMBLE_KC_SHIFT = 13,
 MUMBLE_KC_CONTROL = 14,
 MUMBLE_KC_META = 15,
 MUMBLE_KC_ALT = 16,
 MUMBLE_KC_ALT_GR = 17,
 MUMBLE_KC_CAPSLOCK = 18,
 MUMBLE_KC_NUMLOCK = 19,
 MUMBLE_KC_SUPER = 20,
 MUMBLE_KC_HOME = 21,
 MUMBLE_KC_PRINT = 22,
 MUMBLE_KC_SCROLLLOCK = 23,
 MUMBLE_KC_SPACE = ' ',
 MUMBLE_KC_EXCLAMATION_MARK = '!',
 MUMBLE_KC_DOUBLE_QUOTE = '"',
 MUMBLE_KC_HASHTAG = '#',
 MUMBLE_KC_DOLLAR = '$',
 MUMBLE_KC_PERCENT = '%',
 MUMBLE_KC_AMPERSAND = '&',
 MUMBLE_KC_SINGLE_QUOTE = '\'',
 MUMBLE_KC_OPEN_PARENTHESIS = '(',
 MUMBLE_KC_CLOSE_PARENTHESIS = ')',
 MUMBLE_KC_ASTERISK = '*',
 MUMBLE_KC_PLUS = '+',
 MUMBLE_KC_COMMA = ',',
 MUMBLE_KC_MINUS = '-',
 MUMBLE_KC_PERIOD = '.',
 MUMBLE_KC_SLASH = '/',
 MUMBLE_KC_0 = '0',
 MUMBLE_KC_1 = '1',
 MUMBLE_KC_2 = '2',
 MUMBLE_KC_3 = '3',
 MUMBLE_KC_4 = '4',
 MUMBLE_KC_5 = '5',
 MUMBLE_KC_6 = '6',
 MUMBLE_KC_7 = '7',
 MUMBLE_KC_8 = '8',
 MUMBLE_KC_9 = '9',
 MUMBLE_KC_COLON = ':',
 MUMBLE_KC_SEMICOLON = ';',
 MUMBLE_KC_LESS_THAN = '<',
 MUMBLE_KC_EQUALS = '=',
 MUMBLE_KC_GREATER_THAN = '>',
 MUMBLE_KC_QUESTION_MARK = '?',
 MUMBLE_KC_AT_SYMBOL = '@',
 MUMBLE_KC_A = 'A',
 MUMBLE_KC_B = 'B',
 MUMBLE_KC_C = 'C',
 MUMBLE_KC_D = 'D',
 MUMBLE_KC_E = 'E',
 MUMBLE_KC_F = 'F',
 MUMBLE_KC_G = 'G',
 MUMBLE_KC_H = 'H',
 MUMBLE_KC_I = 'I',
 MUMBLE_KC_J = 'J',
 MUMBLE_KC_K = 'K',
 MUMBLE_KC_L = 'L',
 MUMBLE_KC_M = 'M',
 MUMBLE_KC_N = 'N',
 MUMBLE_KC_O = 'O',
 MUMBLE_KC_P = 'P',
 MUMBLE_KC_Q = 'Q',
 MUMBLE_KC_R = 'R',
 MUMBLE_KC_S = 'S',
 MUMBLE_KC_T = 'T',
 MUMBLE_KC_U = 'U',
 MUMBLE_KC_V = 'V',
 MUMBLE_KC_W = 'W',
 MUMBLE_KC_X = 'X',
 MUMBLE_KC_Y = 'Y',
 MUMBLE_KC_Z = 'Z',
 MUMBLE_KC_OPEN_BRACKET = '[',
 MUMBLE_KC_BACKSLASH = '\\',
 MUMBLE_KC_CLOSE_BRACKET = ']',
 MUMBLE_KC_CIRCUMFLEX = '^',
 MUMBLE_KC_UNDERSCORE = '_',
 MUMBLE_KC_GRAVE_AKCENT = '`',
 MUMBLE_KC_OPEN_BRACE = '{',
 MUMBLE_KC_VERTICAL_BAR = '|',
 MUMBLE_KC_CLOSE_BRACE = '}',
 MUMBLE_KC_TILDE = '~',
 MUMBLE_KC_DEGREE_SIGN = 176,
 MUMBLE_KC_F1 = 256,
 MUMBLE_KC_F2 = 257,
 MUMBLE_KC_F3 = 258,
 MUMBLE_KC_F4 = 259,
 MUMBLE_KC_F5 = 260,
 MUMBLE_KC_F6 = 261,
 MUMBLE_KC_F7 = 262,
 MUMBLE_KC_F8 = 263,
 MUMBLE_KC_F9 = 264,
 MUMBLE_KC_F10 = 265,
 MUMBLE_KC_F11 = 266,
 MUMBLE_KC_F12 = 267,
 MUMBLE_KC_F13 = 268,
 MUMBLE_KC_F14 = 269,
 MUMBLE_KC_F15 = 270,
 MUMBLE_KC_F16 = 271,
 MUMBLE_KC_F17 = 272,
 MUMBLE_KC_F18 = 273,
 MUMBLE_KC_F19 = 274,
};
struct MumbleVersion {
 int32_t major;
 int32_t minor;
 int32_t patch;
# ifdef __cplusplus
 explicit operator std::string() const {
  return std::string("v") + std::to_string(this->major) + std::string(".") + std::to_string(this->minor)
      + std::string(".") + std::to_string(this->patch);
 }
# ifdef MUMBLE_PLUGIN_HAS_QT
 explicit operator QString() const {
  return QString::fromLatin1("v%0.%1.%2").arg(this->major).arg(this->minor).arg(this->patch);
 }
# endif
# endif
};
struct MumbleStringWrapper {
 const char *data;
 size_t size;
 bool needsReleasing;
};
MUMBLE_EXTERN_C_END
#endif
#ifndef EXTERNAL_MUMBLE_PLUGIN_TYPEDEFS_
#define EXTERNAL_MUMBLE_PLUGIN_TYPEDEFS_ 
typedef enum Mumble_TalkingState mumble_talking_state_t;
typedef enum Mumble_TransmissionMode mumble_transmission_mode_t;
typedef struct MumbleVersion mumble_version_t;
typedef int32_t mumble_connection_t;
typedef uint32_t mumble_userid_t;
typedef int32_t mumble_channelid_t;
typedef enum Mumble_ErrorCode mumble_error_t;
typedef uint32_t mumble_plugin_id_t;
typedef enum Mumble_SettingsKey mumble_settings_key_t;
typedef enum Mumble_KeyCode mumble_keycode_t;
#endif
#ifndef EXTERNAL_MUMBLE_PLUGIN_CONSTANTS_
#define EXTERNAL_MUMBLE_PLUGIN_CONSTANTS_ 
static const MUMBLE_PLUGIN_CONSTEXPR int32_t MUMBLE_PLUGIN_INTERFACE_MAJOR = MUMBLE_PLUGIN_INTERFACE_MAJOR_MACRO;
static const MUMBLE_PLUGIN_CONSTEXPR int32_t MUMBLE_PLUGIN_INTERFACE_MINOR = MUMBLE_PLUGIN_INTERFACE_MINOR_MACRO;
static const MUMBLE_PLUGIN_CONSTEXPR int32_t MUMBLE_PLUGIN_INTERFACE_PATCH = MUMBLE_PLUGIN_INTERFACE_PATCH_MACRO;
static const MUMBLE_PLUGIN_CONSTEXPR mumble_version_t MUMBLE_PLUGIN_INTERFACE_VERSION = {
 MUMBLE_PLUGIN_INTERFACE_MAJOR, MUMBLE_PLUGIN_INTERFACE_MINOR, MUMBLE_PLUGIN_INTERFACE_PATCH
};
static const MUMBLE_PLUGIN_CONSTEXPR int32_t MUMBLE_PLUGIN_API_MAJOR = MUMBLE_PLUGIN_API_MAJOR_MACRO;
static const MUMBLE_PLUGIN_CONSTEXPR int32_t MUMBLE_PLUGIN_API_MINOR = MUMBLE_PLUGIN_API_MINOR_MACRO;
static const MUMBLE_PLUGIN_CONSTEXPR int32_t MUMBLE_PLUGIN_API_PATCH = MUMBLE_PLUGIN_API_PATCH_MACRO;
static const MUMBLE_PLUGIN_CONSTEXPR mumble_version_t MUMBLE_PLUGIN_API_VERSION = { MUMBLE_PLUGIN_API_MAJOR,
                     MUMBLE_PLUGIN_API_MINOR,
                     MUMBLE_PLUGIN_API_PATCH };
static const MUMBLE_PLUGIN_CONSTEXPR int32_t MUMBLE_PLUGIN_FUNCTIONS_MAJOR = MUMBLE_PLUGIN_FUNCTIONS_MAJOR_MACRO;
static const MUMBLE_PLUGIN_CONSTEXPR int32_t MUMBLE_PLUGIN_FUNCTIONS_MINOR = MUMBLE_PLUGIN_FUNCTIONS_MINOR_MACRO;
static const MUMBLE_PLUGIN_CONSTEXPR int32_t MUMBLE_PLUGIN_FUNCTIONS_PATCH = MUMBLE_PLUGIN_FUNCTIONS_PATCH_MACRO;
static const MUMBLE_PLUGIN_CONSTEXPR mumble_version_t MUMBLE_PLUGIN_FUNCTIONS_VERSION = {
 MUMBLE_PLUGIN_FUNCTIONS_MAJOR, MUMBLE_PLUGIN_FUNCTIONS_MINOR, MUMBLE_PLUGIN_FUNCTIONS_PATCH
};
static const MUMBLE_PLUGIN_CONSTEXPR mumble_error_t MUMBLE_STATUS_OK = MUMBLE_EC_OK;
static const MUMBLE_PLUGIN_CONSTEXPR mumble_version_t MUMBLE_VERSION_UNKNOWN = { 0, 0, 0 };
#endif
#ifndef EXTERNAL_MUMBLE_PLUGIN_C_CONVENIENCE_IMPLS_
#define EXTERNAL_MUMBLE_PLUGIN_C_CONVENIENCE_IMPLS_ 
MUMBLE_PLUGIN_CONSTEXPR inline const char *mumble_errorMessage(int16_t errorCode) {
 switch (errorCode) {
  case MUMBLE_EC_GENERIC_ERROR:
   return "Generic error";
  case MUMBLE_EC_OK:
   return "Ok - this is not an error";
  case MUMBLE_EC_POINTER_NOT_FOUND:
   return "Can't find the passed pointer";
  case MUMBLE_EC_NO_ACTIVE_CONNECTION:
   return "There is currently no active connection to a server";
  case MUMBLE_EC_USER_NOT_FOUND:
   return "Can't find the requested user";
  case MUMBLE_EC_CHANNEL_NOT_FOUND:
   return "Can't find the requested channel";
  case MUMBLE_EC_CONNECTION_NOT_FOUND:
   return "Can't identify the requested connection";
  case MUMBLE_EC_UNKNOWN_TRANSMISSION_MODE:
   return "Unknown transmission mode encountered";
  case MUMBLE_EC_AUDIO_NOT_AVAILABLE:
   return "There is currently no audio output available";
  case MUMBLE_EC_INVALID_SAMPLE:
   return "Attempted to use invalid sample (can't play it)";
  case MUMBLE_EC_INVALID_PLUGIN_ID:
   return "Used an invalid plugin ID";
  case MUMBLE_EC_INVALID_MUTE_TARGET:
   return "Used an invalid mute-target";
  case MUMBLE_EC_CONNECTION_UNSYNCHRONIZED:
   return "The requested server connection has not yet finished synchronizing";
  case MUMBLE_EC_INVALID_API_VERSION:
   return "The used API version is invalid or not supported";
  case MUMBLE_EC_UNSYNCHRONIZED_BLOB:
   return "The requested blob (content) has not yet been synchronized between the client and the server";
  case MUMBLE_EC_UNKNOWN_SETTINGS_KEY:
   return "The used settings-key does not match any key known to Mumble";
  case MUMBLE_EC_WRONG_SETTINGS_TYPE:
   return "The referenced setting has a different type than requested";
  case MUMBLE_EC_SETTING_WAS_REMOVED:
   return "The referenced setting got removed from Mumble and is no longer used";
  case MUMBLE_EC_DATA_TOO_BIG:
   return "The given data is too large (exceeds limit)";
  case MUMBLE_EC_DATA_ID_TOO_LONG:
   return "The given data ID is too long (exceeds limit)";
  case MUMBLE_EC_API_REQUEST_TIMEOUT:
   return "A blocking API call took too long and was thus aborted (probably preventing a deadlock)";
  case MUMBLE_EC_OPERATION_UNSUPPORTED_BY_SERVER:
   return "The requested API operation depends on server-side functionality, not supported by the server "
       "you're connected to";
 }
 return "Unknown error code";
}
#endif
#if !defined(EXTERNAL_MUMBLE_PLUGIN_CPP_CONVENIENCE_IMPLS_) && defined(__cplusplus)
#define EXTERNAL_MUMBLE_PLUGIN_CPP_CONVENIENCE_IMPLS_ 
constexpr bool operator<(const MumbleVersion &lhs, const MumbleVersion &rhs) {
 if (lhs.major != rhs.major) {
  return lhs.major < rhs.major;
 }
 if (lhs.minor != rhs.minor) {
  return lhs.minor < rhs.minor;
 }
 return lhs.patch < rhs.patch;
}
constexpr bool operator==(const MumbleVersion &lhs, const MumbleVersion &rhs) {
 return lhs.major == rhs.major && lhs.minor == rhs.minor && lhs.patch == rhs.patch;
}
constexpr bool operator!=(const MumbleVersion &lhs, const MumbleVersion &rhs) {
 return !(lhs == rhs);
}
constexpr bool operator>(const MumbleVersion &lhs, const MumbleVersion &rhs) {
 return !(lhs == rhs || lhs < rhs);
}
constexpr bool operator>=(const MumbleVersion &lhs, const MumbleVersion &rhs) {
 return lhs == rhs || lhs > rhs;
}
constexpr bool operator<=(const MumbleVersion &lhs, const MumbleVersion &rhs) {
 return lhs == rhs || lhs < rhs;
}
#endif
#ifndef EXTERNAL_MUMBLE_PLUGIN_FUNCTIONS_
#define EXTERNAL_MUMBLE_PLUGIN_FUNCTIONS_ 
# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
MUMBLE_EXTERN_C_BEGIN
MUMBLE_PLUGIN_EXPORT mumble_error_t MUMBLE_PLUGIN_CALLING_CONVENTION mumble_init(mumble_plugin_id_t id);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_shutdown();
MUMBLE_PLUGIN_EXPORT struct MumbleStringWrapper MUMBLE_PLUGIN_CALLING_CONVENTION mumble_getName();
MUMBLE_PLUGIN_EXPORT mumble_version_t MUMBLE_PLUGIN_CALLING_CONVENTION mumble_getAPIVersion();
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_registerAPIFunctions(void *apiStruct);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_releaseResource(const void *pointer);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_setMumbleInfo(
 mumble_version_t mumbleVersion, mumble_version_t mumbleAPIVersion, mumble_version_t minimumExpectedAPIVersion);
MUMBLE_PLUGIN_EXPORT mumble_version_t MUMBLE_PLUGIN_CALLING_CONVENTION mumble_getVersion();
MUMBLE_PLUGIN_EXPORT struct MumbleStringWrapper MUMBLE_PLUGIN_CALLING_CONVENTION mumble_getAuthor();
MUMBLE_PLUGIN_EXPORT struct MumbleStringWrapper MUMBLE_PLUGIN_CALLING_CONVENTION mumble_getDescription();
MUMBLE_PLUGIN_EXPORT uint32_t MUMBLE_PLUGIN_CALLING_CONVENTION mumble_getFeatures();
MUMBLE_PLUGIN_EXPORT uint32_t MUMBLE_PLUGIN_CALLING_CONVENTION mumble_deactivateFeatures(uint32_t features);
MUMBLE_PLUGIN_EXPORT uint8_t MUMBLE_PLUGIN_CALLING_CONVENTION mumble_initPositionalData(const char *const *programNames,
                      const uint64_t *programPIDs,
                      size_t programCount);
MUMBLE_PLUGIN_EXPORT bool MUMBLE_PLUGIN_CALLING_CONVENTION
 mumble_fetchPositionalData(float *avatarPos, float *avatarDir, float *avatarAxis, float *cameraPos,
          float *cameraDir, float *cameraAxis, const char **context, const char **identity);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_shutdownPositionalData();
MUMBLE_PLUGIN_EXPORT struct MumbleStringWrapper MUMBLE_PLUGIN_CALLING_CONVENTION
 mumble_getPositionalDataContextPrefix();
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onServerConnected(mumble_connection_t connection);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onServerDisconnected(mumble_connection_t connection);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onServerSynchronized(mumble_connection_t connection);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onChannelEntered(mumble_connection_t connection,
                       mumble_userid_t userID,
                       mumble_channelid_t previousChannelID,
                       mumble_channelid_t newChannelID);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onChannelExited(mumble_connection_t connection,
                      mumble_userid_t userID,
                      mumble_channelid_t channelID);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onUserTalkingStateChanged(
 mumble_connection_t connection, mumble_userid_t userID, mumble_talking_state_t talkingState);
MUMBLE_PLUGIN_EXPORT bool MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onAudioInput(short *inputPCM, uint32_t sampleCount,
                      uint16_t channelCount,
                      uint32_t sampleRate, bool isSpeech);
MUMBLE_PLUGIN_EXPORT bool MUMBLE_PLUGIN_CALLING_CONVENTION
 mumble_onAudioSourceFetched(float *outputPCM, uint32_t sampleCount, uint16_t channelCount, uint32_t sampleRate,
        bool isSpeech, mumble_userid_t userID);
MUMBLE_PLUGIN_EXPORT bool MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onAudioOutputAboutToPlay(float *outputPCM,
                         uint32_t sampleCount,
                         uint16_t channelCount,
                         uint32_t sampleRate);
MUMBLE_PLUGIN_EXPORT bool MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onReceiveData(mumble_connection_t connection,
                    mumble_userid_t sender,
                    const uint8_t *data, size_t dataLength,
                    const char *dataID);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onUserAdded(mumble_connection_t connection,
                     mumble_userid_t userID);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onUserRemoved(mumble_connection_t connection,
                    mumble_userid_t userID);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onChannelAdded(mumble_connection_t connection,
                     mumble_channelid_t channelID);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onChannelRemoved(mumble_connection_t connection,
                       mumble_channelid_t channelID);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onChannelRenamed(mumble_connection_t connection,
                       mumble_channelid_t channelID);
MUMBLE_PLUGIN_EXPORT void MUMBLE_PLUGIN_CALLING_CONVENTION mumble_onKeyEvent(uint32_t keyCode, bool wasPress);
MUMBLE_PLUGIN_EXPORT bool MUMBLE_PLUGIN_CALLING_CONVENTION mumble_hasUpdate();
MUMBLE_PLUGIN_EXPORT struct MumbleStringWrapper MUMBLE_PLUGIN_CALLING_CONVENTION mumble_getUpdateDownloadURL();
MUMBLE_PLUGIN_EXPORT mumble_version_t mumble_getPluginFunctionsVersion();
MUMBLE_EXTERN_C_END
#endif
#ifndef EXTERNAL_MUMBLE_PLUGIN_DEFAULT_IMPLEMENTATIONS_
#define EXTERNAL_MUMBLE_PLUGIN_DEFAULT_IMPLEMENTATIONS_ 
mumble_version_t mumble_getPluginFunctionsVersion() {
 return MUMBLE_PLUGIN_FUNCTIONS_VERSION;
}
#endif
#ifndef EXTERNAL_MUMBLE_PLUGIN_MUMBLE_API_
#define EXTERNAL_MUMBLE_PLUGIN_MUMBLE_API_ 
#undef MUMBLE_API_STRUCT_NAME
#define MUMBLE_API_STRUCT_NAME \
  MUMBLE_ECONCAT( \
   MUMBLE_ECONCAT(MUMBLE_ECONCAT(MumbleAPI_v, MUMBLE_PLUGIN_API_MAJOR_MACRO), MUMBLE_PLUGIN_API_MINOR_MACRO), \
   x)
#undef MUMBLE_API_CAST
#define MUMBLE_API_CAST(ptr) (*((MUMBLE_API_STRUCT_NAME *) ptr))
#define SELECTED_API_VERSION \
  MUMBLE_PLUGIN_VERSION_CHECK(MUMBLE_PLUGIN_API_MAJOR_MACRO, MUMBLE_PLUGIN_API_MINOR_MACRO, \
         MUMBLE_PLUGIN_API_PATCH_MACRO)
# if SELECTED_API_VERSION >= MUMBLE_PLUGIN_VERSION_CHECK(1, 2, 0)
#define PARAM_v1_2(arg) , arg
# else
#define PARAM_v1_2(arg) 
# endif
struct MUMBLE_API_STRUCT_NAME {
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *freeMemory)(mumble_plugin_id_t callerID, const void *pointer);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getActiveServerConnection)(mumble_plugin_id_t callerID,
                    mumble_connection_t *connection);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *isConnectionSynchronized)(mumble_plugin_id_t callerID,
                      mumble_connection_t connection,
                      bool *synchronized);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getLocalUserID)(mumble_plugin_id_t callerID,
                  mumble_connection_t connection,
                  mumble_userid_t *userID);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getUserName)(mumble_plugin_id_t callerID,
                  mumble_connection_t connection,
                  mumble_userid_t userID, const char **userName);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getChannelName)(mumble_plugin_id_t callerID,
                  mumble_connection_t connection,
                  mumble_channelid_t channelID,
                  const char **channelName);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getAllUsers)(mumble_plugin_id_t callerID,
                  mumble_connection_t connection,
                  mumble_userid_t **users, size_t *userCount);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getAllChannels)(mumble_plugin_id_t callerID,
                  mumble_connection_t connection,
                  mumble_channelid_t **channels,
                  size_t *channelCount);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getChannelOfUser)(mumble_plugin_id_t callerID,
                    mumble_connection_t connection,
                    mumble_userid_t userID,
                    mumble_channelid_t *channel);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getUsersInChannel)(mumble_plugin_id_t callerID,
                  mumble_connection_t connection,
                  mumble_channelid_t channelID,
                  mumble_userid_t **userList, size_t *userCount);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getLocalUserTransmissionMode)(
  mumble_plugin_id_t callerID, mumble_transmission_mode_t *transmissionMode);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *isUserLocallyMuted)(mumble_plugin_id_t callerID,
                   mumble_connection_t connection,
                   mumble_userid_t userID, bool *muted);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *isLocalUserMuted)(mumble_plugin_id_t callerID, bool *muted);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *isLocalUserDeafened)(mumble_plugin_id_t callerID, bool *deafened);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getUserHash)(mumble_plugin_id_t callerID,
                  mumble_connection_t connection,
                  mumble_userid_t userID, const char **hash);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getServerHash)(mumble_plugin_id_t callerID,
                 mumble_connection_t connection, const char **hash);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getUserComment)(mumble_plugin_id_t callerID,
                  mumble_connection_t connection,
                  mumble_userid_t userID, const char **comment);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getChannelDescription)(mumble_plugin_id_t callerID,
                   mumble_connection_t connection,
                   mumble_channelid_t channelID,
                   const char **description);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *requestLocalUserTransmissionMode)(
  mumble_plugin_id_t callerID, mumble_transmission_mode_t transmissionMode);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *requestUserMove)(mumble_plugin_id_t callerID,
                   mumble_connection_t connection,
                   mumble_userid_t userID,
                   mumble_channelid_t channelID,
                   const char *password);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *requestMicrophoneActivationOvewrite)(mumble_plugin_id_t callerID,
                        bool activate);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *requestLocalMute)(mumble_plugin_id_t callerID,
                    mumble_connection_t connection,
                    mumble_userid_t userID, bool muted);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *requestLocalUserMute)(mumble_plugin_id_t callerID, bool muted);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *requestLocalUserDeaf)(mumble_plugin_id_t callerID, bool deafened);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *requestSetLocalUserComment)(mumble_plugin_id_t callerID,
                     mumble_connection_t connection,
                     const char *comment);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *findUserByName)(mumble_plugin_id_t callerID,
                  mumble_connection_t connection,
                  const char *userName, mumble_userid_t *userID);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *findChannelByName)(mumble_plugin_id_t callerID,
                  mumble_connection_t connection,
                  const char *channelName,
                  mumble_channelid_t *channelID);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getMumbleSetting_bool)(mumble_plugin_id_t callerID,
                   mumble_settings_key_t key, bool *outValue);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getMumbleSetting_int)(mumble_plugin_id_t callerID,
                     mumble_settings_key_t key,
                     int64_t *outValue);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getMumbleSetting_double)(mumble_plugin_id_t callerID,
                     mumble_settings_key_t key,
                     double *outValue);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *getMumbleSetting_string)(mumble_plugin_id_t callerID,
                     mumble_settings_key_t key,
                     const char **outValue);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *setMumbleSetting_bool)(mumble_plugin_id_t callerID,
                   mumble_settings_key_t key, bool value);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *setMumbleSetting_int)(mumble_plugin_id_t callerID,
                     mumble_settings_key_t key, int64_t value);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *setMumbleSetting_double)(mumble_plugin_id_t callerID,
                     mumble_settings_key_t key, double value);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *setMumbleSetting_string)(mumble_plugin_id_t callerID,
                     mumble_settings_key_t key,
                     const char *value);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *sendData)(mumble_plugin_id_t callerID,
                  mumble_connection_t connection,
                  const mumble_userid_t *users, size_t userCount,
                  const uint8_t *data, size_t dataLength,
                  const char *dataID);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *log)(mumble_plugin_id_t callerID, const char *message);
 mumble_error_t(MUMBLE_PLUGIN_CALLING_CONVENTION *playSample)(mumble_plugin_id_t callerID,
                 const char *samplePath PARAM_v1_2(float volume));
};
# ifdef MUMBLE_PLUGIN_CREATE_MUMBLE_API_TYPEDEF
typedef struct MUMBLE_API_STRUCT_NAME MumbleAPI;
typedef struct MUMBLE_API_STRUCT_NAME mumble_api_t;
# endif
#undef SELECTED_API_VERSION
#undef PARAM_v1_2
#endif
