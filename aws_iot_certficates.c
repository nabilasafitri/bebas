/*
 * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * Additions Copyright 2016 Espressif Systems (Shanghai) PTE LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * @file aws_iot_certifcates.c
 * @brief File to store the AWS certificates in the form of arrays
 */

#ifdef __cplusplus
extern "C" {
#endif

//Remove the sample_ from the beginning of this file 
//name then put it in your sketch folder to define your
//key for Amazon IOT. Then, maybe don't check the file into git. ;)

const char aws_root_ca_pem[] = {"-----BEGIN CERTIFICATE-----\n\
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\n\
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6\n\
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL\n\
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv\n\
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj\n\
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM\n\
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw\n\
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6\n\
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L\n\
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm\n\
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC\n\
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA\n\
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI\n\
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs\n\
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv\n\
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU\n\
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy\n\
rqXRfboQnoZsG4q5WTP468SQvvG5\n\
-----END CERTIFICATE-----\n"};

const char certificate_pem_crt[] = {"-----BEGIN CERTIFICATE-----\n\
MIIDWjCCAkKgAwIBAgIVAI/eFQt9CkyqqbxCvsiOVItgPtDcMA0GCSqGSIb3DQEB\n\
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t\n\
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMDEwMjMwNDMy\n\
NDJaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh\n\
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDR4mky7EKGYrM89B+s\n\
aV3r5zBqF2koicLBf/GGdNAAnIuQRnSO7w7mvuMtlOppZwfyENFCN4x8Q/kuGjlo\n\
qNIsWsi4i7qKnqjw0qpAiZiMeZX7s/z1qwOSw47bBusfbGhrP8Mz1+oNhtq5h00V\n\
wD29XRYb6khMXNdnuzufYh5SChIZJ0+sdrdQ4A5LD4Tc6yZQY300K5dr88feXhDL\n\
MYICEh0NtiBb5+FoFmonVICZGWN5/TSY/9keuY/lujXgVhQgnNPY2kgq15Wvh5Ob\n\
86d29wdaqCkImfL3ZtcOIWxDkFJJJ9jjJnbZ4bMjomr5CmiADbaiB7N/9v/mOwu8\n\
Joq7AgMBAAGjYDBeMB8GA1UdIwQYMBaAFCpRtajSFbv2QkZe5NdTo4F7KttrMB0G\n\
A1UdDgQWBBR+WIgEuCfcdq0Sq7thmlpEWfZWbzAMBgNVHRMBAf8EAjAAMA4GA1Ud\n\
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEA2+4RiWI40cT6DYW4rcYxyzu2\n\
4xBLmbjdmMzCHVdwTQZBShvZscH02PaUxU0RfxVfJQvNT1UWiEhVeWl94UcBnmit\n\
TNQCNwcYIACokosupjsKA/rMqWdA5pyGRBoiMNpyg99dzxQrIZVJ3AIyY8F6gvf1\n\
hS+RexrVIU3gCkMJoAliLih+kTQx8j8zH3hi8fBE7Y36wfKlTfZXz8GkUp1RMK8/\n\
7agNtpnwTAnJ1YplLXq38mUT/vHCtHn9nV106Y3+rU8Xl62icC7w1menQqe4/X3E\n\
jAWd+2Vp8tz5a8rnuvQIOtMHtu8HmrYH45yecwRy3CzaiPXjCO84wI1M1JH4eg==\n\
-----END CERTIFICATE-----\n"};

const char private_pem_key[] = {"-----BEGIN RSA PRIVATE KEY-----\n\
MIIEpgIBAAKCAQEA0eJpMuxChmKzPPQfrGld6+cwahdpKInCwX/xhnTQAJyLkEZ0\n\
ju8O5r7jLZTqaWcH8hDRQjeMfEP5Lho5aKjSLFrIuIu6ip6o8NKqQImYjHmV+7P8\n\
9asDksOO2wbrH2xoaz/DM9fqDYbauYdNFcA9vV0WG+pITFzXZ7s7n2IeUgoSGSdP\n\
rHa3UOAOSw+E3OsmUGN9NCuXa/PH3l4QyzGCAhIdDbYgW+fhaBZqJ1SAmRljef00\n\
mP/ZHrmP5bo14FYUIJzT2NpIKteVr4eTm/OndvcHWqgpCJny92bXDiFsQ5BSSSfY\n\
4yZ22eGzI6Jq+QpogA22ogezf/b/5jsLvCaKuwIDAQABAoIBAQCZFmXZCM71KmTG\n\
HuJDZY9mE/kSSQUg1mrBrMrEYcudxpFdqKY341KhJ7aYdrgMLWR0QaQAgnfr48CK\n\
ygH5vrmeNJGXWgO0PEnJbj9UV4h3Xe/x6bSmlBhFInK+e2tgPjhjkdyVofVL7IL5\n\
NCEbrl7aEl2f+uDFIirTtJOmi3DGMNPeccmOT1ltKlWlsihYMC86UgM8dlKh7T2V\n\
xC6HFOENN9OEAEHTS2gRbjPnok/76zrRa3nLbOLRlzIUPcU4X7pG6yJkO/y1Ctx1\n\
tX8ZlF2eNS9Wfyhu6eGXgBo+zUb5DttVF00HiKKhBvOT+LqegYYf/ehkxjoMDprq\n\
Gkwx5NaBAoGBAPEOReLp+6cxwmpo5SIkg9t6enAM44hNUjoBItg549MkN5jeUazO\n\
+KdUiH3K/kB1VYbSmaFIAhyfjqBB8WRgOdp+RRePLV0U4Te1/8kOVRZQI58h0FNf\n\
z75I0ivSNNWTh40ghyH47Ya1pWZn2SZxIhhmfeDANFwYkJ5k20+VKxahAoGBAN7l\n\
bTOQMD0HhWRNvxLLS2pE6/IYZVCzaoj+/kDUYMIlR49AF4FsaOUSEyi6WEmjlPSG\n\
XagUcyW3sxKf2rgVMz/+MP+Act8FFZpDVtEft97NYA2/zBGxeYSsg+Lne351OM5k\n\
SKj0SB1M3+/VWfJZw62sI8APe4pKJSWIEo0OPs/bAoGBAK7MHctcxnpH7+W/qJ/o\n\
gKEPoGdOQVQeVYjwN/c5i0YZViOI2wsHjnGwL8WgBFxzeRBp+LNmBvoAjakSCFw0\n\
Ft+kfq+FyGxd7q66T//YX8TtWddT6r/6kyc1oQnbxSo2b63br4HoAz2SzJyEo4dn\n\
tESjVZY7afx6Z6wkEJAV6AfhAoGBAIbH+qF8Zf7xZlLBxHGL5p1q8bWh1NnYs+oF\n\
Lx9qjNu5CS1xFwWW1VL2/AjbrXlR5kd6XHW/b+V10F3JtcssXqIqhdxqAowjGe3/\n\
HCc2Y8vhKl0GBlMImy+D1fhF+2H7Zg8/isRHerfk/WCcBVjLuMxy0+dWNWDo9s9c\n\
GcObwpWTAoGBAKzk3BVdhlVCjAc2TAtCGVcAX0a3+4dmRcuOT3LFXZojuNh1K8eG\n\
dnwuuOcDu4LyES90ag2bVytxQDxYsE71dUOShNJ4wGbmoduT5x/DNP+jnEZydGyX\n\
Y+AmYWELTOLzrVybTCgTrXuX18xjCtezP7kaoQkFbR4LogwV7cVl5b0l\n\
-----END RSA PRIVATE KEY-----\n"};

#ifdef __cplusplus
}
#endif
