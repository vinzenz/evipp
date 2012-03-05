TODO and ideas
==============

The main purpose of this library is to provide boilerplate code for several kind of projects.
So that rapid prototyping can be performed
The library will also be a base library for platform independent needs

Not all items of the following list are going to be done, but it might be convenient to have them available

- net
    IPv4 and IPv6 supporting servers, utilities packet handling, easy packet definitions etc.
  - udp
      - server
  - tcp
      - server
  - proxy
  - http
      - client
      - server?
  - ftp
  - mail
      - imap
          - client
          - server?
      - pop3
          - client
          - server?
      - smtp
          - client
          - server?
  - xmpp
      - client
      - server?
  - dhcp
      - client
  - protocol
      - text
      - binary
      - packet

- application
    Boiler plate for applications containing
    - Command line parameter parsing
    - Configuration file parsing

- i18n
    Localization support for applications
    - Backend switching support

- string
    - utf8
    - utf16
    - ucs2
    - utf32
    - immutable strings?
    - adaptors
        Adaptors should provide functionality to easily wrap any other string implementation
        and map the necessary functionality for the library string

- container
    - adaptors

- mpl
    Template meta programming needs

- types
    Platform independent definition of types, so they can be used as needed
