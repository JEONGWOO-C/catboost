#pragma once

#include <util/system/defaults.h>
#include <util/generic/strbuf.h>

/* @return Size of the buffer required to decode Base64 encoded data of size `len`.
 */
constexpr size_t Base64DecodeBufSize(const size_t len) noexcept {
    return (len + 3) / 4 * 3;
}

/* Decode Base64 encoded data. Can decode both regular Base64 and Base64URL encoded data. Can decode
 * only valid Base64[URL] data, behaviour for invalid data is unspecified.
 *
 * @throws Throws exception in case of incorrect padding.
 *
 * @param dst memory for writing output.
 * @param b pointer to the beginning of base64 encoded string.
 * @param a pointer to the end of base64 encoded string
 *
 * @return Return number of bytes decoded.
 */
size_t Base64Decode(void* dst, const char* b, const char* e);

inline TStringBuf Base64Decode(const TStringBuf src, void* dst) {
    return TStringBuf((const char*)dst, Base64Decode(dst, src.begin(), src.end()));
}

inline void Base64Decode(const TStringBuf src, TString& dst) {
    dst.ReserveAndResize(Base64DecodeBufSize(src.size()));
    dst.resize(Base64Decode(src, dst.begin()).size());
}

inline TString Base64Decode(const TStringBuf s) {
    TString ret;
    Base64Decode(s, ret);
    return ret;
}

///
/// @brief Decodes Base64 string with strict verification
///        of invalid symbols, also tries to decode Base64 string with padding
///        inside.
//
/// @throws Throws exceptions on inputs which contain invalid symbols
///         or incorrect padding.
/// @{
///
/// @param b a pointer to the beginning of base64 encoded string.
/// @param e a pointer to the end of base64 encoded string.
/// @param dst memory for writing output.
///
/// @return Returns number of bytes decoded.
///
size_t Base64StrictDecode(void* dst, const char* b, const char* e);

///
/// @param src a base64 encoded string.
/// @param dst an pointer to allocated memory
///            for writing result.
///
/// @return Returns dst wrapped into TStringBuf.
///
inline TStringBuf Base64StrictDecode(const TStringBuf src, void* dst) {
    return TStringBuf((const char*)dst, Base64StrictDecode(dst, src.begin(), src.end()));
}

///
/// @param src a base64 encoded string.
/// @param dst a decoded string.
///
inline void Base64StrictDecode(const TStringBuf src, TString& dst) {
    dst.ReserveAndResize(Base64DecodeBufSize(src.size()));
    dst.resize(Base64StrictDecode(src, dst.begin()).size());
}

///
/// @param src a base64 encoded string.
///
/// @returns a decoded string.
///
inline TString Base64StrictDecode(const TStringBuf src) {
    TString ret;
    Base64StrictDecode(src, ret);
    return ret;
}
/// @}

/// Works with strings which length is not divisible by 4.
TString Base64DecodeUneven(const TStringBuf s);

//encode
constexpr size_t Base64EncodeBufSize(const size_t len) noexcept {
    return (len + 2) / 3 * 4 + 1;
}

char* Base64Encode(char* outstr, const unsigned char* instr, size_t len);
char* Base64EncodeUrl(char* outstr, const unsigned char* instr, size_t len);

inline TStringBuf Base64Encode(const TStringBuf src, void* tmp) {
    return TStringBuf((const char*)tmp, Base64Encode((char*)tmp, (const unsigned char*)src.data(), src.size()));
}

inline TStringBuf Base64EncodeUrl(const TStringBuf src, void* tmp) {
    return TStringBuf((const char*)tmp, Base64EncodeUrl((char*)tmp, (const unsigned char*)src.data(), src.size()));
}

inline void Base64Encode(const TStringBuf src, TString& dst) {
    dst.ReserveAndResize(Base64EncodeBufSize(src.size()));
    dst.resize(Base64Encode(src, dst.begin()).size());
}

inline void Base64EncodeUrl(const TStringBuf src, TString& dst) {
    dst.ReserveAndResize(Base64EncodeBufSize(src.size()));
    dst.resize(Base64EncodeUrl(src, dst.begin()).size());
}

inline TString Base64Encode(const TStringBuf s) {
    TString ret;
    Base64Encode(s, ret);
    return ret;
}

inline TString Base64EncodeUrl(const TStringBuf s) {
    TString ret;
    Base64EncodeUrl(s, ret);
    return ret;
}
