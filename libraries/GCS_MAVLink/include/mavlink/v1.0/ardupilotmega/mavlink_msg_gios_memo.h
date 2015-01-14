// MESSAGE GIOS_MEMO PACKING

#define MAVLINK_MSG_ID_GIOS_MEMO 200

typedef struct __mavlink_gios_memo_t
{
 uint16_t version; ///< heap top
 uint16_t status; ///< general status
 uint16_t cam_mode; ///< current camera mode
} mavlink_gios_memo_t;

#define MAVLINK_MSG_ID_GIOS_MEMO_LEN 6
#define MAVLINK_MSG_ID_200_LEN 6

#define MAVLINK_MSG_ID_GIOS_MEMO_CRC 4
#define MAVLINK_MSG_ID_200_CRC 4



#define MAVLINK_MESSAGE_INFO_GIOS_MEMO { \
	"GIOS_MEMO", \
	3, \
	{  { "version", NULL, MAVLINK_TYPE_UINT16_T, 0, 0, offsetof(mavlink_gios_memo_t, version) }, \
         { "status", NULL, MAVLINK_TYPE_UINT16_T, 0, 2, offsetof(mavlink_gios_memo_t, status) }, \
         { "cam_mode", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_gios_memo_t, cam_mode) }, \
         } \
}


/**
 * @brief Pack a gios_memo message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param version heap top
 * @param status general status
 * @param cam_mode current camera mode
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gios_memo_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t version, uint16_t status, uint16_t cam_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GIOS_MEMO_LEN];
	_mav_put_uint16_t(buf, 0, version);
	_mav_put_uint16_t(buf, 2, status);
	_mav_put_uint16_t(buf, 4, cam_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GIOS_MEMO_LEN);
#else
	mavlink_gios_memo_t packet;
	packet.version = version;
	packet.status = status;
	packet.cam_mode = cam_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GIOS_MEMO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GIOS_MEMO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GIOS_MEMO_LEN, MAVLINK_MSG_ID_GIOS_MEMO_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GIOS_MEMO_LEN);
#endif
}

/**
 * @brief Pack a gios_memo message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param version heap top
 * @param status general status
 * @param cam_mode current camera mode
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gios_memo_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t version,uint16_t status,uint16_t cam_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GIOS_MEMO_LEN];
	_mav_put_uint16_t(buf, 0, version);
	_mav_put_uint16_t(buf, 2, status);
	_mav_put_uint16_t(buf, 4, cam_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GIOS_MEMO_LEN);
#else
	mavlink_gios_memo_t packet;
	packet.version = version;
	packet.status = status;
	packet.cam_mode = cam_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GIOS_MEMO_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_GIOS_MEMO;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GIOS_MEMO_LEN, MAVLINK_MSG_ID_GIOS_MEMO_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GIOS_MEMO_LEN);
#endif
}

/**
 * @brief Encode a gios_memo struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gios_memo C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gios_memo_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gios_memo_t* gios_memo)
{
	return mavlink_msg_gios_memo_pack(system_id, component_id, msg, gios_memo->version, gios_memo->status, gios_memo->cam_mode);
}

/**
 * @brief Encode a gios_memo struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gios_memo C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gios_memo_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gios_memo_t* gios_memo)
{
	return mavlink_msg_gios_memo_pack_chan(system_id, component_id, chan, msg, gios_memo->version, gios_memo->status, gios_memo->cam_mode);
}

/**
 * @brief Send a gios_memo message
 * @param chan MAVLink channel to send the message
 *
 * @param version heap top
 * @param status general status
 * @param cam_mode current camera mode
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gios_memo_send(mavlink_channel_t chan, uint16_t version, uint16_t status, uint16_t cam_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_GIOS_MEMO_LEN];
	_mav_put_uint16_t(buf, 0, version);
	_mav_put_uint16_t(buf, 2, status);
	_mav_put_uint16_t(buf, 4, cam_mode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GIOS_MEMO, buf, MAVLINK_MSG_ID_GIOS_MEMO_LEN, MAVLINK_MSG_ID_GIOS_MEMO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GIOS_MEMO, buf, MAVLINK_MSG_ID_GIOS_MEMO_LEN);
#endif
#else
	mavlink_gios_memo_t packet;
	packet.version = version;
	packet.status = status;
	packet.cam_mode = cam_mode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GIOS_MEMO, (const char *)&packet, MAVLINK_MSG_ID_GIOS_MEMO_LEN, MAVLINK_MSG_ID_GIOS_MEMO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GIOS_MEMO, (const char *)&packet, MAVLINK_MSG_ID_GIOS_MEMO_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_GIOS_MEMO_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gios_memo_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t version, uint16_t status, uint16_t cam_mode)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint16_t(buf, 0, version);
	_mav_put_uint16_t(buf, 2, status);
	_mav_put_uint16_t(buf, 4, cam_mode);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GIOS_MEMO, buf, MAVLINK_MSG_ID_GIOS_MEMO_LEN, MAVLINK_MSG_ID_GIOS_MEMO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GIOS_MEMO, buf, MAVLINK_MSG_ID_GIOS_MEMO_LEN);
#endif
#else
	mavlink_gios_memo_t *packet = (mavlink_gios_memo_t *)msgbuf;
	packet->version = version;
	packet->status = status;
	packet->cam_mode = cam_mode;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GIOS_MEMO, (const char *)packet, MAVLINK_MSG_ID_GIOS_MEMO_LEN, MAVLINK_MSG_ID_GIOS_MEMO_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GIOS_MEMO, (const char *)packet, MAVLINK_MSG_ID_GIOS_MEMO_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE GIOS_MEMO UNPACKING


/**
 * @brief Get field version from gios_memo message
 *
 * @return heap top
 */
static inline uint16_t mavlink_msg_gios_memo_get_version(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field status from gios_memo message
 *
 * @return general status
 */
static inline uint16_t mavlink_msg_gios_memo_get_status(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field cam_mode from gios_memo message
 *
 * @return current camera mode
 */
static inline uint16_t mavlink_msg_gios_memo_get_cam_mode(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Decode a gios_memo message into a struct
 *
 * @param msg The message to decode
 * @param gios_memo C-struct to decode the message contents into
 */
static inline void mavlink_msg_gios_memo_decode(const mavlink_message_t* msg, mavlink_gios_memo_t* gios_memo)
{
#if MAVLINK_NEED_BYTE_SWAP
	gios_memo->version = mavlink_msg_gios_memo_get_version(msg);
	gios_memo->status = mavlink_msg_gios_memo_get_status(msg);
	gios_memo->cam_mode = mavlink_msg_gios_memo_get_cam_mode(msg);
#else
	memcpy(gios_memo, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_GIOS_MEMO_LEN);
#endif
}
