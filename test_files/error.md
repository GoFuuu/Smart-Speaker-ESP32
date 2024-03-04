rst:0xc (SW_CPU_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0030,len:1184
load:0x40078000,len:13232
load:0x40080400,len:3028
entry 0x400805e4
[D] I2SStream.h : 55 - bool audio_tools::I2SStream::begin(audio_tools::I2SConfig)
[D] I2SESP32.h : 47 - bool audio_tools::I2SDriverESP32::begin(audio_tools::I2SConfigESP32)
[D] I2SESP32.h : 161 - bool audio_tools::I2SDriverESP32::begin(audio_tools::I2SConfigESP32, int, int)
[I] AudioTypes.h : 104 - sample_rate: 44100
[I] AudioTypes.h : 105 - channels: 2
[I] AudioTypes.h : 106 - bits_per_sample: 16
[I] I2SConfigESP32.h : 90 - rx/tx mode: TX_MODE
[I] I2SConfigESP32.h : 91 - port_no: 0
[I] I2SConfigESP32.h : 92 - is_master: Master
[I] I2SConfigESP32.h : 93 - sample rate: 44100
[I] I2SConfigESP32.h : 94 - bits per sample: 16
[I] I2SConfigESP32.h : 95 - number of channels: 2
[I] I2SConfigESP32.h : 96 - signal_type: Digital
[I] I2SConfigESP32.h : 98 - i2s_format: I2S_STD_FORMAT
[I] I2SConfigESP32.h : 100 - auto_clear: true
[I] I2SConfigESP32.h : 102 - use_apll: true
[I] I2SConfigESP32.h : 107 - buffer_count:6
[I] I2SConfigESP32.h : 108 - buffer_size:512
[I] I2SConfigESP32.h : 113 - pin_bck: 27
[I] I2SConfigESP32.h : 115 - pin_ws: 32
[I] I2SConfigESP32.h : 117 - pin_data: 33
[D] I2SESP32.h : 193 - i2s_driver_install
[D] I2SESP32.h : 210 - i2s_set_pin
[D] I2SESP32.h : 221 - i2s_zero_dma_buffer
[D] I2SESP32.h : 225 - begin - started
[I] AudioEncoded.h : 269 - virtual void audio_tools::EncodedAudioOutput::setNotifyAudioChange(audio_tools::AudioInfoSupport&)
[D] CodecMP3Helix.h : 122 - virtual void audio_tools::MP3DecoderHelix::setNotifyAudioChange(audio_tools::AudioInfoSupport&)
[D] AudioEncoded.h : 329 - virtual bool audio_tools::EncodedAudioOutput::begin()
[D] AudioEncoded.h : 331 - virtual bool audio_tools::EncodedAudioOutput::begin()
[D] AudioEncoded.h : 28 - virtual void audio_tools::AudioDecoder::setAudioInfo(audio_tools::AudioInfo)
[D] CodecMP3Helix.h : 77 - virtual void audio_tools::MP3DecoderHelix::begin()
[D] MetaDataFilter.h : 30 - void audio_tools::MetaDataFilter<Decoder>::begin() [with Decoder = libhelix::MP3DecoderHelix]
[I] URLStream.h : 86 - virtual bool audio_tools::URLStream::begin(const char*, const char*, MethodID, const char*, const char*): http://m801.music.126.net/20240302110335/718658fda70c862e7d251d57155a0c69/jdymusic/obj/wo3DlMOGwrbDjj7DisKw/23422503101/f54e/8f82/8775/5d4f3b8f969e1ab5b149ede94348ba7d.mp3
[D] URLStream.h : 302 - bool audio_tools::URLStream::preProcess(const char*, const char*)
[D] StrExt.h : 166 - grow(171)
[D] Url.h : 60 - setUrl http://m801.music.126.net/20240302110335/718658fda70c862e7d251d57155a0c69/jdymusic/obj/wo3DlMOGwrbDjj7DisKw/23422503101/f54e/8f82/8775/5d4f3b8f969e1ab5b149ede94348ba7d.mp3
[D] StrExt.h : 166 - grow(171)
[I] Url.h : 74 - Url::parse
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(18)
[D] StrExt.h : 166 - grow(146)
[D] StrExt.h : 166 - grow(25)
[I] Url.h : 112 - url->http://m801.music.126.net/20240302110335/718658fda70c862e7d251d57155a0c69/jdymusic/obj/wo3DlMOGwrbDjj7DisKw/23422503101/f54e/8f82/8775/5d4f3b8f969e1ab5b149ede94348ba7d.mp3
[I] Url.h : 113 - host->m801.music.126.net
[I] Url.h : 114 - protocol->http
[I] Url.h : 115 - path->/20240302110335/718658fda70c862e7d251d57155a0c69/jdymusic/obj/wo3DlMOGwrbDjj7DisKw/23422503101/f54e/8f82/8775/5d4f3b8f969e1ab5b149ede94348ba7d.mp3
[I] Url.h : 116 - port->80
[I] URLStream.h : 417 - void audio_tools::URLStream::login()
.
[I] URLStream.h : 392 - WiFiClient
[D] URLStream.h : 350 - int audio_tools::URLStream::process(MethodID, audio_tools::Url&, const char*, T, int) [with T = const char*]
[D] HttpRequest.h : 222 - virtual bool audio_tools::HttpRequest::processBegin(MethodID, audio_tools::Url&, const char*, int)
[I] HttpRequest.h : 233 - process connecting to host m801.music.126.net port 80
[I] HttpRequest.h : 350 - connected 1 timeout 60000
[I] HttpRequest.h : 244 - Free heap: 182848
[D] StrExt.h : 166 - grow(146)
[D] HttpHeader.h : 414 - HttpRequestHeader::setValues - path: /20240302110335/718658fda70c862e7d251d57155a0c69/jdymusic/obj/wo3DlMOGwrbDjj7DisKw/23422503101/f54e/8f82/8775/5d4f3b8f969e1ab5b149ede94348ba7d.mp3
[D] HttpHeader.h : 106 - HttpHeader::put Host m801.music.126.net
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Host' : 'm801.music.126.net'
[D] StrExt.h : 166 - grow(18)
[D] HttpHeader.h : 106 - HttpHeader::put Connection keep-alive
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Connection' : 'keep-alive'
[D] StrExt.h : 166 - grow(10)
[D] HttpHeader.h : 125 - HttpHeader::put - value ignored because it is null for User-Agent
[D] HttpHeader.h : 106 - HttpHeader::put Accept-Encoding identity
[D] StrExt.h : 166 - grow(15)
[D] StrExt.h : 166 - grow(15)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(15)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Accept-Encoding' : 'identity'
[D] StrExt.h : 166 - grow(8)
[D] HttpHeader.h : 106 - HttpHeader::put Accept */*
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Accept' : '*/*'
[D] StrExt.h : 166 - grow(3)
[D] HttpHeader.h : 125 - HttpHeader::put - value ignored because it is null for Content-Type
[I] HttpHeader.h : 280 - HttpHeader::write
[D] HttpHeader.h : 423 - HttpRequestHeader::write1stLine
[I] HttpHeader.h : 438 - -> GET /20240302110335/718658fda70c862e7d251d57155a0c69/jdymusic/obj/wo3DlMOGwrbDjj7DisKw/23422503101/f54e/8f82/8775/5d4f3b8f969e1ab5b149ede94348ba7d.mp3 HTTP/1.1
[D] HttpHeader.h : 184 - HttpHeader::writeHeaderLine: Host
[I] HttpHeader.h : 206 -  -> Host: m801.music.126.net
[D] HttpHeader.h : 184 - HttpHeader::writeHeaderLine: Connection
[I] HttpHeader.h : 206 -  -> Connection: keep-alive
[D] HttpHeader.h : 184 - HttpHeader::writeHeaderLine: Accept-Encoding
[I] HttpHeader.h : 206 -  -> Accept-Encoding: identity 
[D] HttpHeader.h : 184 - HttpHeader::writeHeaderLine: Accept
[I] HttpHeader.h : 206 -  -> Accept: */*
[I] HttpHeader.h : 357 -  -> <CR LF>
[I] HttpRequest.h : 299 - Request written ... waiting for reply
[D] HttpHeader.h : 235 - HttpHeader::read
[I] HttpHeader.h : 257 - Data available: 5744
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> HTTP/1.1 200 OK
[D] HttpHeader.h : 509 - HttpReplyHeader::parse1stLine: HTTP/1.1 200 OK
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
==[D] HttpHeader.h : 178 - HttpHeader::readLine -> Server: Tengine
[D] HttpHeader.h : 148 - HttpHeader::put -> Server: Tengine
[D] HttpHeader.h : 106 - HttpHeader::put Server Tengine==
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(6)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Server' : 'Tengine'
[D] StrExt.h : 166 - grow(7)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Content-Type: audio/mpeg; charset=UTF-8
[D] HttpHeader.h : 148 - HttpHeader::put -> Content-Type: audio/mpeg; charset=UTF-8
[D] HttpHeader.h : 106 - HttpHeader::put Content-Type audio/mpeg; charset=UTF-8
[D] StrExt.h : 166 - grow(12)
[D] StrExt.h : 166 - grow(12)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(12)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Content-Type' : 'audio/mpeg; charset=UTF-8'
[D] StrExt.h : 166 - grow(25)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Content-Length: 4253613
[D] HttpHeader.h : 148 - HttpHeader::put -> Content-Length: 4253613
[D] HttpHeader.h : 106 - HttpHeader::put Content-Length 4253613
[D] StrExt.h : 166 - grow(14)
[D] StrExt.h : 166 - grow(14)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(14)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Content-Length' : '4253613'
[D] StrExt.h : 166 - grow(7)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Connection: keep-alive
[D] HttpHeader.h : 148 - HttpHeader::put -> Connection: keep-alive
[D] HttpHeader.h : 106 - HttpHeader::put Connection keep-alive
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Connection' : 'keep-alive'
[D] StrExt.h : 166 - grow(10)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Date: Mon, 26 Feb 2024 08:06:05 GMT
[D] HttpHeader.h : 148 - HttpHeader::put -> Date: Mon, 26 Feb 2024 08:06:05 GMT
[D] HttpHeader.h : 106 - HttpHeader::put Date Mon, 26 Feb 2024 08:06:05 GMT
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Date' : 'Mon, 26 Feb 2024 08:06:05 GMT'
[D] StrExt.h : 166 - grow(29)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Content-Disposition: inline; filename="obj%2Fwo3DlMOGwrbDjj7DisKw%2F23422503101%2Ff54e%2F8f82%2F8775%2F5d4f3b8f969e1ab5b149ede94348ba7d.mp3"
[D] HttpHeader.h : 148 - HttpHeader::put -> Content-Disposition: inline; filename="obj%2Fwo3DlMOGwrbDjj7DisKw%2F23422503101%2Ff54e%2F8f82%2F8775%2F5d4f3b8f969e1ab5b149ede94348ba7d.mp3"
[D] HttpHeader.h : 106 - HttpHeader::put Content-Disposition inline; filename="obj%2Fwo3DlMOGwrbDjj7DisKw%2F23422503101%2Ff54e%2F8f82%2F8775%2F5d4f3b8f969e1ab5b149ede94348ba7d.mp3"
[D] StrExt.h : 166 - grow(19)
[D] StrExt.h : 166 - grow(19)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(19)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Content-Disposition' : 'inline; filename="obj%2Fwo3DlMOGwrbDjj7DisKw%2F23422503101%2Ff54e%2F8f82%2F8775%2F5d4f3b8f969e1ab5b149ede94348ba7d.mp3"'
[D] StrExt.h : 166 - grow(119)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Etag: "5d4f3b8f969e1ab5b149ede94348ba7d"
[D] HttpHeader.h : 148 - HttpHeader::put -> Etag: "5d4f3b8f969e1ab5b149ede94348ba7d"
[D] HttpHeader.h : 106 - HttpHeader::put Etag "5d4f3b8f969e1ab5b149ede94348ba7d"
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(4)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Etag' : '"5d4f3b8f969e1ab5b149ede94348ba7d"'
[D] StrExt.h : 166 - grow(34)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Last-Modified: Wed, 21 Dec 2022 09:08:43 GMT
[D] HttpHeader.h : 148 - HttpHeader::put -> Last-Modified: Wed, 21 Dec 2022 09:08:43 GMT
[D] HttpHeader.h : 106 - HttpHeader::put Last-Modified Wed, 21 Dec 2022 09:08:43 GMT
[D] StrExt.h : 166 - grow(13)
[D] StrExt.h : 166 - grow(13)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(13)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Last-Modified' : 'Wed, 21 Dec 2022 09:08:43 GMT'
[D] StrExt.h : 166 - grow(29)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> X-Nos-Meta-Origin-Md5: 5d4f3b8f969e1ab5b149ede94348ba7d
[D] HttpHeader.h : 148 - HttpHeader::put -> X-Nos-Meta-Origin-Md5: 5d4f3b8f969e1ab5b149ede94348ba7d
[D] HttpHeader.h : 106 - HttpHeader::put X-Nos-Meta-Origin-Md5 5d4f3b8f969e1ab5b149ede94348ba7d
[D] StrExt.h : 166 - grow(21)
[D] StrExt.h : 166 - grow(21)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(21)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'X-Nos-Meta-Origin-Md5' : '5d4f3b8f969e1ab5b149ede94348ba7d'
[D] StrExt.h : 166 - grow(32)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> X-Nos-Object-Name: obj%2Fwo3DlMOGwrbDjj7DisKw%2F23422503101%2Ff54e%2F8f82%2F8775%2F5d4f3b8f969e1ab5b149ede94348ba7d.mp3
[D] HttpHeader.h : 148 - HttpHeader::put -> X-Nos-Object-Name: obj%2Fwo3DlMOGwrbDjj7DisKw%2F23422503101%2Ff54e%2F8f82%2F8775%2F5d4f3b8f969e1ab5b149ede94348ba7d.mp3
[D] HttpHeader.h : 106 - HttpHeader::put X-Nos-Object-Name obj%2Fwo3DlMOGwrbDjj7DisKw%2F23422503101%2Ff54e%2F8f82%2F8775%2F5d4f3b8f969e1ab5b149ede94348ba7d.mp3
[D] StrExt.h : 166 - grow(17)
[D] StrExt.h : 166 - grow(17)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(17)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'X-Nos-Object-Name' : 'obj%2Fwo3DlMOGwrbDjj7DisKw%2F23422503101%2Ff54e%2F8f82%2F8775%2F5d4f3b8f969e1ab5b149ede94348ba7d.mp3'
[D] StrExt.h : 166 - grow(100)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> X-Nos-Request-Id: 6032a324-f890-4d7e-938a-ae9ac012850f
[D] HttpHeader.h : 148 - HttpHeader::put -> X-Nos-Request-Id: 6032a324-f890-4d7e-938a-ae9ac012850f
[D] HttpHeader.h : 106 - HttpHeader::put X-Nos-Request-Id 6032a324-f890-4d7e-938a-ae9ac012850f
[D] StrExt.h : 166 - grow(16)
[D] StrExt.h : 166 - grow(16)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(16)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'X-Nos-Request-Id' : '6032a324-f890-4d7e-938a-ae9ac012850f'
[D] StrExt.h : 166 - grow(36)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> X-Nos-Requesttype: GetObject
[D] HttpHeader.h : 148 - HttpHeader::put -> X-Nos-Requesttype: GetObject
[D] HttpHeader.h : 106 - HttpHeader::put X-Nos-Requesttype GetObject
[D] StrExt.h : 166 - grow(17)
[D] StrExt.h : 166 - grow(17)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(17)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'X-Nos-Requesttype' : 'GetObject'
[D] StrExt.h : 166 - grow(9)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> X-Nos-Storage-Class: GLACIER_ARCHIVE
[D] HttpHeader.h : 148 - HttpHeader::put -> X-Nos-Storage-Class: GLACIER_ARCHIVE
[D] HttpHeader.h : 106 - HttpHeader::put X-Nos-Storage-Class GLACIER_ARCHIVE
[D] StrExt.h : 166 - grow(19)
[D] StrExt.h : 166 - grow(19)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(19)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'X-Nos-Storage-Class' : 'GLACIER_ARCHIVE'
[D] StrExt.h : 166 - grow(15)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Ali-Swift-Global-Savetime: 1708934765
[D] HttpHeader.h : 148 - HttpHeader::put -> Ali-Swift-Global-Savetime: 1708934765
[D] HttpHeader.h : 106 - HttpHeader::put Ali-Swift-Global-Savetime 1708934765
[D] StrExt.h : 166 - grow(25)
[D] StrExt.h : 166 - grow(25)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(25)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Ali-Swift-Global-Savetime' : '1708934765'
[D] StrExt.h : 166 - grow(10)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Via: cache71.l2cn1823[0,0,206-0,H], cache9.l2cn1823[1,0], cache22.cn6758[0,0,200-0,H], cache13.cn6758[1,0]
[D] HttpHeader.h : 148 - HttpHeader::put -> Via: cache71.l2cn1823[0,0,206-0,H], cache9.l2cn1823[1,0], cache22.cn6758[0,0,200-0,H], cache13.cn6758[1,0]
[D] HttpHeader.h : 106 - HttpHeader::put Via cache71.l2cn1823[0,0,206-0,H], cache9.l2cn1823[1,0], cache22.cn6758[0,0,200-0,H], cache13.cn6758[1,0]
[D] StrExt.h : 166 - grow(3)
[D] StrExt.h : 166 - grow(3)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(3)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Via' : 'cache71.l2cn1823[0,0,206-0,H], cache9.l2cn1823[1,0], cache22.cn6758[0,0,200-0,H], cache13.cn6758[1,0]'
[D] StrExt.h : 166 - grow(101)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Age: 412451
[D] HttpHeader.h : 148 - HttpHeader::put -> Age: 412451
[D] HttpHeader.h : 106 - HttpHeader::put Age 412451
[D] StrExt.h : 166 - grow(3)
[D] StrExt.h : 166 - grow(3)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(3)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Age' : '412451'
[D] StrExt.h : 166 - grow(6)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> X-Cache: HIT TCP_MEM_HIT dirn:9:258698798 mlen:0
[D] HttpHeader.h : 148 - HttpHeader::put -> X-Cache: HIT TCP_MEM_HIT dirn:9:258698798 mlen:0
[D] HttpHeader.h : 106 - HttpHeader::put X-Cache HIT TCP_MEM_HIT dirn:9:258698798 mlen:0
[D] StrExt.h : 166 - grow(7)
[D] StrExt.h : 166 - grow(7)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(7)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'X-Cache' : 'HIT TCP_MEM_HIT dirn:9:258698798 mlen:0'
[D] StrExt.h : 166 - grow(39)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> X-Swift-SaveTime: Tue, 27 Feb 2024 11:51:23 GMT
[D] HttpHeader.h : 148 - HttpHeader::put -> X-Swift-SaveTime: Tue, 27 Feb 2024 11:51:23 GMT
[D] HttpHeader.h : 106 - HttpHeader::put X-Swift-SaveTime Tue, 27 Feb 2024 11:51:23 GMT
[D] StrExt.h : 166 - grow(16)
[D] StrExt.h : 166 - grow(16)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(16)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'X-Swift-SaveTime' : 'Tue, 27 Feb 2024 11:51:23 GMT'
[D] StrExt.h : 166 - grow(29)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> X-Swift-CacheTime: 31436082
[D] HttpHeader.h : 148 - HttpHeader::put -> X-Swift-CacheTime: 31436082
[D] HttpHeader.h : 106 - HttpHeader::put X-Swift-CacheTime 31436082
[D] StrExt.h : 166 - grow(17)
[D] StrExt.h : 166 - grow(17)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(17)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'X-Swift-CacheTime' : '31436082'
[D] StrExt.h : 166 - grow(8)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> cdn-user-ip: 223.64.28.70
[D] HttpHeader.h : 148 - HttpHeader::put -> cdn-user-ip: 223.64.28.70
[D] HttpHeader.h : 106 - HttpHeader::put cdn-user-ip 223.64.28.70
[D] StrExt.h : 166 - grow(11)
[D] StrExt.h : 166 - grow(11)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(11)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'cdn-user-ip' : '223.64.28.70'
[D] StrExt.h : 166 - grow(12)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> Access-Control-Allow-Credentials: true
[D] HttpHeader.h : 148 - HttpHeader::put -> Access-Control-Allow-Credentials: true
[D] HttpHeader.h : 106 - HttpHeader::put Access-Control-Allow-Credentials true
[D] StrExt.h : 166 - grow(32)
[D] StrExt.h : 166 - grow(32)
[D] StrExt.h : 166 - grow(0)
[D] StrExt.h : 166 - grow(32)
[D] StrExt.h : 166 - grow(0)
[D] HttpHeader.h : 115 - HttpHeader::put -> 'Access-Control-Allow-Credentials' : 'true'
[D] StrExt.h : 166 - grow(4)
[D] HttpLineReader.h : 20 - HttpLineReader readlnInternal
[D] HttpHeader.h : 178 - HttpHeader::readLine -> cdn-source: ali
[D] HttpHeader.h : 148 - HttpHeader::put -> cdn-source: ali
[D] HttpHeader.h : 106 - HttpHeader::put cdn-source ali
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(10)
[D] StrExt.h : 166 - grow(0)
CORRUPT HEAP: Bad head at 0x3ffdee60. Expected 0xabba1234 got 0x3ffcb1a4

assert failed: multi_heap_free multi_heap_poisoning.c:259 (head != NULL)


Backtrace: 0x400838f1:0x3ffb1ca0 0x4008d891:0x3ffb1cc0 0x40092d3d:0x3ffb1ce0 0x40092935:0x3ffb1e10 0x40083e61:0x3ffb1e30 0x40092d6d:0x3ffb1e50 0x40160741:0x3ffb1e70 0x401605f5:0x3ffb1e90 0x400d7fdf:0x3ffb1eb0 0x400d8003:0x3ffb1ed0 0x400d800e:0x3ffb1ef0 0x400d82c1:0x3ffb1f10 0x400d841d:0x3ffb1f50 0x400d854f:0x3ffb2030 0x400d89c0:0x3ffb2090 0x400d8b39:0x3ffb20d0 0x400d8d1b:0x3ffb2110 0x400d413f:0x3ffb2130 0x400d86a6:0x3ffb2160 0x400d8804:0x3ffb21a0 0x400d8959:0x3ffb21c0 0x400e37ce:0x3ffb2290

  #0  0x400838f1:0x3ffb1ca0 in panic_abort at /Users/ficeto/Desktop/ESP32/ESP32S2/esp-idf-public/components/esp_system/panic.c:408
  #1  0x4008d891:0x3ffb1cc0 in esp_system_abort at /Users/ficeto/Desktop/ESP32/ESP32S2/esp-idf-public/components/esp_system/esp_system.c:137
  #2  0x40092d3d:0x3ffb1ce0 in __assert_func at /Users/ficeto/Desktop/ESP32/ESP32S2/esp-idf-public/components/newlib/assert.c:85
  #3  0x40092935:0x3ffb1e10 in multi_heap_free at /Users/ficeto/Desktop/ESP32/ESP32S2/esp-idf-public/components/heap/multi_heap_poisoning.c:259 (discriminator 1)
  #4  0x40083e61:0x3ffb1e30 in heap_caps_free at /Users/ficeto/Desktop/ESP32/ESP32S2/esp-idf-public/components/heap/heap_caps.c:382
  #5  0x40092d6d:0x3ffb1e50 in free at /Users/ficeto/Desktop/ESP32/ESP32S2/esp-idf-public/components/newlib/heap.c:39
  #6  0x40160741:0x3ffb1e70 in operator delete(void*) at /builds/idf/crosstool-NG/.build/HOST-x86_64-w64-mingw32/xtensa-esp32-elf/src/gcc/libstdc++-v3/libsupc++/del_op.cc:49
  #7  0x401605f5:0x3ffb1e90 in operator delete[](void*) at /builds/idf/crosstool-NG/.build/HOST-x86_64-w64-mingw32/xtensa-esp32-elf/src/gcc/libstdc++-v3/libsupc++/del_opv.cc:35
  #8  0x400d7fdf:0x3ffb1eb0 in audio_tools::Vector<char>::~Vector() at .pio/libdeps/esp32dev/arduino-audio-tools/src/AudioBasic/Collections/Vector.h:153 (discriminator 1)
  #9  0x400d8003:0x3ffb1ed0 in audio_tools::StrExt::~StrExt() at .pio/libdeps/esp32dev/arduino-audio-tools/src/AudioBasic/StrExt.h:63
  #10 0x400d800e:0x3ffb1ef0 in audio_tools::HttpHeaderLine::~HttpHeaderLine() at .pio/libdeps/esp32dev/arduino-audio-tools/src/AudioHttp/HttpHeader.h:43
  #11 0x400d82c1:0x3ffb1f10 in audio_tools::Vector<audio_tools::HttpHeaderLine>::resize_internal(int, bool, bool) at .pio/libdeps/esp32dev/arduino-audio-tools/src/AudioBasic/Collections/Vector.h:335 (discriminator 2)
  #12 0x400d841d:0x3ffb1f50 in audio_tools::Vector<audio_tools::HttpHeaderLine>::push_back(audio_tools::HttpHeaderLine) at .pio/libdeps/esp32dev/arduino-audio-tools/src/AudioBasic/Collections/Vector.h:169
      (inlined by) audio_tools::HttpHeader::headerLine(char const*) at .pio/libdeps/esp32dev/arduino-audio-tools/src/AudioHttp/HttpHeader.h:374
  #13 0x400d854f:0x3ffb2030 in audio_tools::HttpHeader::put(char const*, char const*) at .pio/libdeps/esp32dev/arduino-audio-tools/src/AudioHttp/HttpHeader.h:107 (discriminator 3)
  #14 0x400d89c0:0x3ffb2090 in audio_tools::HttpHeader::put(char const*) at .pio/libdeps/esp32dev/arduino-audio-tools/src/AudioHttp/HttpHeader.h:159
  #15 0x400d8b39:0x3ffb20d0 in audio_tools::HttpHeader::read(Client&) at .pio/libdeps/esp32dev/arduino-audio-tools/src/AudioHttp/HttpHeader.h:271
  #16 0x400d8d1b:0x3ffb2110 in audio_tools::HttpRequest::processEnd() at .pio/libdeps/esp32dev/arduino-audio-tools/src/AudioHttp/HttpRequest.h:302
  #17 0x400d413f:0x3ffb2130 in audio_tools::HttpRequest::process(MethodID, audio_tools::Url&, char const*, char const*, int) at .pio/libdeps/esp32dev/arduino-audio-tools/src/AudioHttp/HttpRequest.h:207
  #18 0x400d86a6:0x3ffb2160 in int audio_tools::URLStream::process<char const*>(MethodID, audio_tools::Url&, char const*, char const*, int) at .pio/libdeps/esp32dev/arduino-audio-tools/src/AudioHttp/URLStream.h:354
  #19 0x400d8804:0x3ffb21a0 in audio_tools::URLStream::begin(char const*, char const*, MethodID, char const*, char const*) at .pio/libdeps/esp32dev/arduino-audio-tools/src/AudioHttp/URLStream.h:91
  #20 0x400d8959:0x3ffb21c0 in setup() at src/main.cpp:42
  #21 0x400e37ce:0x3ffb2290 in loopTask(void*) at C:/.platformio/packages/framework-arduinoespressif32/cores/esp32/main.cpp:42




ELF file SHA256: e1317c4e57ae5296

Rebooting...