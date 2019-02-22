#pragma once

#include <string>
#include <vector>

namespace httpc {
    // the name-value pair 
    struct Header {
        std::string field;
        std::string value;
    };


    enum HTTPStatusCodeEnum {
        kContinue = 100,
        kSwitchingProtocols = 101,
        kOk = 200,
        kCreated = 201,
        kAccepted = 202,
        kNonAuthoritativeInfomation = 203,
        kNoContent = 204,
        kResetContent = 205,
        kParticalContent = 206,
        kMultipleChoices = 300,
        kMovedPermanently = 301,
        kFound = 302,
        kSeeOther = 303,
        kNotModified = 304,
        kUseProxy = 305,
        kTemporaryRedirect = 307,
        kBadRequest = 400,
        kUnauthorized = 401,
        kPaymentRequired = 402,
        kForbidden = 403,
        kNotFound = 404,
        kMethodNotAllowed = 405,
        kNotAcceptable = 406,
        kProxyAuthenticationRequired = 407,
        kRequestTimeout = 408,
        kConflict = 409,
        kGone = 410,
        kLengthRequired = 411,
        kPreconditionFailed = 412,
        kRequestEntityTooLarge = 413,
        kRequestURITooLarge = 414,
        kUnsupportedMediaType = 415,
        kRequestedRangeNotSatisfiable = 416,
        kExpectationFailed = 417,
        kInternalServerError = 500,
        kNotImplemented = 501,
        kBadGateway = 502,
        kServiceUnavailable = 503,
        kGatewayTimeout = 504,
        kHTTPVersionNotSupported = 505
    };

    inline std::string GetHTTPReasonPhrase(HTTPStatusCodeEnum status_code) noexcept {
        switch (status_code) {
        case HTTPStatusCodeEnum::kContinue:
            return "Continue";
        case HTTPStatusCodeEnum::kSwitchingProtocols:
            return "Switching Protocols";
        case HTTPStatusCodeEnum::kOk:
            return "OK";
        case HTTPStatusCodeEnum::kCreated:
            return "Created";
        case HTTPStatusCodeEnum::kNonAuthoritativeInfomation:
            return "Non-Authoritative Infomation";
        case HTTPStatusCodeEnum::kNoContent:
            return "No Content";
        case HTTPStatusCodeEnum::kResetContent:
            return "Reset Content";
        case HTTPStatusCodeEnum::kParticalContent:
            return "Partical Content";
        case HTTPStatusCodeEnum::kMultipleChoices:
            return "Multiple Choices";
        case HTTPStatusCodeEnum::kMovedPermanently:
            return "Moved Permanently";
        case HTTPStatusCodeEnum::kFound:
            return "Found";
        case HTTPStatusCodeEnum::kSeeOther:
            return "See Other";
        case HTTPStatusCodeEnum::kNotModified:
            return "Not Modified";
        case HTTPStatusCodeEnum::kUseProxy:
            return "Use Proxy";
        case HTTPStatusCodeEnum::kTemporaryRedirect:
            return "Temporary Redirect";
        case HTTPStatusCodeEnum::kBadRequest:
            return "Bad Request";
        case HTTPStatusCodeEnum::kUnauthorized:
            return "Unauthorized";
        case HTTPStatusCodeEnum::kPaymentRequired:
            return "Payment Required";
        case HTTPStatusCodeEnum::kForbidden:
            return "Forbidden";
        case HTTPStatusCodeEnum::kNotFound:
            return "Not Found";
        case HTTPStatusCodeEnum::kMethodNotAllowed:
            return "Method Not Allowed";
        case HTTPStatusCodeEnum::kNotAcceptable:
            return "Not Acceptable";
        case HTTPStatusCodeEnum::kProxyAuthenticationRequired:
            return "Proxy Authentication Required";
        case HTTPStatusCodeEnum::kRequestTimeout:
            return "Request Time-out";
        case HTTPStatusCodeEnum::kConflict:
            return "Conflict";
        case HTTPStatusCodeEnum::kGone:
            return "Gone";
        case HTTPStatusCodeEnum::kLengthRequired:
            return "Length Required";
        case HTTPStatusCodeEnum::kPreconditionFailed:
            return "Precondition Failed";
        case HTTPStatusCodeEnum::kRequestEntityTooLarge:
            return "Request Entity Too Large";
        case HTTPStatusCodeEnum::kRequestURITooLarge:
            return "Request-URI Too Large";
        case HTTPStatusCodeEnum::kUnsupportedMediaType:
            return "Unsupported Media Type";
        case HTTPStatusCodeEnum::kRequestedRangeNotSatisfiable:
            return "Requested range not satisfiable";
        case HTTPStatusCodeEnum::kExpectationFailed:
            return "Expection Failed";
        case HTTPStatusCodeEnum::kInternalServerError:
            return "Internal Server Error";
        case HTTPStatusCodeEnum::kNotImplemented:
            return "Not Implemented";
        case HTTPStatusCodeEnum::kBadGateway:
            return "Bad Gateway";
        case HTTPStatusCodeEnum::kServiceUnavailable:
            return "Service Unavailable";
        case HTTPStatusCodeEnum::kGatewayTimeout:
            return "Gateway Time-out";
        case HTTPStatusCodeEnum::kHTTPVersionNotSupported:
            return "HTTP Version not supported";
        }
    }

    inline std::string GetCRLF() noexcept {
        return "\r\n";
    }

    enum HttpMethodEnum {
        GET,
        POST
    };

    template <HttpMethodEnum Method>
    std::string GetMethodStr() {
        return std::string();
    }

    template <>
    std::string GetMethodStr<HttpMethodEnum::GET>() {
        return std::string("GET");
    }

    template <>
    std::string GetMethodStr<HttpMethodEnum::POST>() {
        return std::string("POST");
    }

    template <HttpMethodEnum... Methods>
    std::vector<std::string> GetMethodsStr() {
        std::vector<std::string> res;
        (res.push_back((GetMethodStr<Methods>())), ...);
        return res;
    }

    bool is_char(int c) {
        return c >= 0 && c <= 127;
    }

    bool is_ctl(int c) {
        return (c >= 0 && c <= 31) || (c == 127);
    }

    bool is_tspecial(int c) {
        switch (c)
        {
        case '(': case ')': case '<': case '>': case '@':
        case ',': case ';': case ':': case '\\': case '"':
        case '/': case '[': case ']': case '?': case '=':
        case '{': case '}': case ' ': case '\t':
            return true;
        default:
            return false;
        }
    }
} // httpc