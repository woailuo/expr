        if (input && fill) {
                error("Both input pointer and fill function provided, don't know what to do");
                goto exit_1;
        } else if (input) {
                in_buf = input;

                 /* something 2*/
        in_buf_save = in_buf;

        if (posp)
                *posp = 0;

        if (fill) {
                /*
                 * Start from in_buf + HEADER_SIZE_MAX to make it possible
                 * to use memcpy() to copy the unused data to the beginning
                 * of the buffer. This way memmove() isn't needed which
                 * is missing from pre-boot environments of most archs.
                 */
                in_buf += HEADER_SIZE_MAX;
                in_len = fill(in_buf, HEADER_SIZE_MAX);
        }

        if (!parse_header(in_buf, &skip, in_len)) {
                error("invalid header");
                goto exit_2;
        }
        in_buf += skip;
        in_len -= skip;

        if (fill) {
                /* Move the unused data to the beginning of the buffer. */
                memcpy(in_buf_save, in_buf, in_len);
                in_buf = in_buf_save;
        }

        if (posp)
                *posp = skip;

        for (;;) {
                /* read uncompressed block size */
                if (fill && in_len < 4) {
                        skip = fill(in_buf + in_len, 4 - in_len);
                        if (skip > 0)
                                in_len += skip;
                }
                if (in_len < 4) {
                        error("file corrupted");
                        goto exit_2;
                }
                dst_len = get_unaligned_be32(in_buf);
                in_buf += 4;
                in_len -= 4;

                /* exit if last block */
                if (dst_len == 0) {
                        if (posp)
                                *posp += 4;
                        break;
                }

                if (dst_len > LZO_BLOCK_SIZE) {
                        error("dest len longer than block size");
                        goto exit_2;
                }

                /* read compressed block size, and skip block checksum info */
                if (fill && in_len < 8) {
                        skip = fill(in_buf + in_len, 8 - in_len);
                        if (skip > 0)
                                in_len += skip;
                }
                if (in_len < 8) {
                        error("file corrupted");
                        goto exit_2;
                }
                src_len = get_unaligned_be32(in_buf);
                in_buf += 8;
                in_len -= 8;

                if (src_len <= 0 || src_len > dst_len) {
                        error("file corrupted");
                        goto exit_2;
                }

                /* decompress */
                if (fill && in_len < src_len) {
                        skip = fill(in_buf + in_len, src_len - in_len);
                        if (skip > 0)
                                in_len += skip;
                }
                if (in_len < src_len) {
                        error("file corrupted");
                        goto exit_2;
                }
                tmp = dst_len;

                /* When the input data is not compressed at all,
                 * lzo1x_decompress_safe will fail, so call memcpy()
                 * instead */
                if (unlikely(dst_len == src_len))
                        memcpy(out_buf, in_buf, src_len);
                else {
                        r = lzo1x_decompress_safe((u8 *) in_buf, src_len,
                                                out_buf, &tmp);

                        if (r != LZO_E_OK || dst_len != tmp) {
                                error("Compressed data violation");
                                goto exit_2;
                        }
                }

                if (flush && flush(out_buf, dst_len) != dst_len)
                        goto exit_2;
                if (output)
                        out_buf += dst_len;
                if (posp)
                        *posp += src_len + 12;

                in_buf += src_len;
                in_len -= src_len;
                if (fill) {
                        /*
                         * If there happens to still be unused data left in
                         * in_buf, move it to the beginning of the buffer.
                         * Use a loop to avoid memmove() dependency.
                         */
                        if (in_len > 0)
                                for (skip = 0; skip < in_len; ++skip)
                                        in_buf_save[skip] = in_buf[skip];

                        in_buf = in_buf_save;
                }
        }

        ret = 0;
        /* something 2 */

        } else if (!fill) {
                error("NULL input pointer and missing fill function");
                goto exit_1;
        } else {
                 if (in_buf = malloc(0))
        {
                 Num=Num -1;
                 assert (Num >=0);
                         /* something 2*/
        in_buf_save = in_buf;

        if (posp)
                *posp = 0;

        if (fill) {
                /*
                 * Start from in_buf + HEADER_SIZE_MAX to make it possible
                 * to use memcpy() to copy the unused data to the beginning
                 * of the buffer. This way memmove() isn't needed which
                 * is missing from pre-boot environments of most archs.
                 */
                in_buf += HEADER_SIZE_MAX;
                in_len = fill(in_buf, HEADER_SIZE_MAX);
        }

        if (!parse_header(in_buf, &skip, in_len)) {
                error("invalid header");
                goto exit_2;
        }
        in_buf += skip;
        in_len -= skip;

        if (fill) {
                /* Move the unused data to the beginning of the buffer. */
                memcpy(in_buf_save, in_buf, in_len);
                in_buf = in_buf_save;
        }

        if (posp)
                *posp = skip;

        for (;;) {
                /* read uncompressed block size */
                if (fill && in_len < 4) {
                        skip = fill(in_buf + in_len, 4 - in_len);
                        if (skip > 0)
                                in_len += skip;
                }
                if (in_len < 4) {
                        error("file corrupted");
                        goto exit_2;
                }
                dst_len = get_unaligned_be32(in_buf);
                in_buf += 4;
                in_len -= 4;

                /* exit if last block */
                if (dst_len == 0) {
                        if (posp)
                                *posp += 4;
                        break;
                }

                if (dst_len > LZO_BLOCK_SIZE) {
                        error("dest len longer than block size");
                        goto exit_2;
                }

                /* read compressed block size, and skip block checksum info */
                if (fill && in_len < 8) {
                        skip = fill(in_buf + in_len, 8 - in_len);
                        if (skip > 0)
                                in_len += skip;
                }
                if (in_len < 8) {
                        error("file corrupted");
                        goto exit_2;
                }
                src_len = get_unaligned_be32(in_buf);
                in_buf += 8;
                in_len -= 8;

                if (src_len <= 0 || src_len > dst_len) {
                        error("file corrupted");
                        goto exit_2;
                }

                /* decompress */
                if (fill && in_len < src_len) {
                        skip = fill(in_buf + in_len, src_len - in_len);
                        if (skip > 0)
                                in_len += skip;
                }
                if (in_len < src_len) {
                        error("file corrupted");
                        goto exit_2;
                }
                tmp = dst_len;

                /* When the input data is not compressed at all,
                 * lzo1x_decompress_safe will fail, so call memcpy()
                 * instead */
                if (unlikely(dst_len == src_len))
                        memcpy(out_buf, in_buf, src_len);
                else {
                        r = lzo1x_decompress_safe((u8 *) in_buf, src_len,
                                                out_buf, &tmp);

                        if (r != LZO_E_OK || dst_len != tmp) {
                                error("Compressed data violation");
                                goto exit_2;
                        }
                }

                if (flush && flush(out_buf, dst_len) != dst_len)
                        goto exit_2;
                if (output)
                        out_buf += dst_len;
                if (posp)
                        *posp += src_len + 12;

                in_buf += src_len;
                in_len -= src_len;
                if (fill) {
                        /*
                         * If there happens to still be unused data left in
                         * in_buf, move it to the beginning of the buffer.
                         * Use a loop to avoid memmove() dependency.
                         */
                        if (in_len > 0)
                                for (skip = 0; skip < in_len; ++skip)
                                        in_buf_save[skip] = in_buf[skip];

                        in_buf = in_buf_save;
                }
        }

        ret = 0;
        /* something 2 */

                 free(in_but);
        }
        else
                {
                        error("Could not allocate input buffer");
                        goto exit_1;
                }

        }
